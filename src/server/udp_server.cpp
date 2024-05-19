#include "udp_server.hpp"
#include "map.hpp"
#include "message_handler.hpp"
#include <spdlog/spdlog.h>

void udp_server::start_receive() {
  socket_.async_receive_from(
      boost::asio::buffer(recv_buffer_), remote_endpoint_,
      [this](auto err, auto rx_bytes) { this->handle_receive(err, rx_bytes); });
}
void udp_server::handle_receive(const boost::system::error_code &error,
                                std::size_t bytes_transferred) {
  if (!error) {
    std::string request(
        recv_buffer_.data(),
        bytes_transferred); // TODO: extra copy, use string view?
    spdlog::debug("received {} bytes", bytes_transferred);
    spdlog::trace("received {}", request);
    auto decoded_request = protocol::json_serializer::deserialize(request);
    // FIXME: nested lambdas below aren't that readable
    auto send = [this](std::shared_ptr<std::string> response) {
      this->socket_.async_send_to(boost::asio::buffer(*response),
                                  this->remote_endpoint_,
                                  [this, response](auto err, auto bytes_tx) {
                                    this->handle_send(response, err, bytes_tx);
                                  });
    };
    message_handler handler(send, map);
    std::visit(handler, decoded_request);

    start_receive();
  } else {
    spdlog::warn("failed to receive message: {}", error.message());
  }
}
void udp_server::handle_send(std::shared_ptr<std::string> message_ptr,
                             const boost::system::error_code &error,
                             std::size_t bytes_transferred) {
  if (!error) {
    const auto &msg = *message_ptr; // don't dereference within logger
    spdlog::debug("sent {} bytes", bytes_transferred);
    spdlog::trace("message sent: {}", msg);
  } else {
    spdlog::warn("failed to send message: {}", error.message());
  }
}
udp_server::udp_server(boost::asio::io_context &io_context,
                       unsigned port_number, Map &map)
    : socket_(io_context, udp::endpoint(udp::v4(), port_number)), map(map) {
  spdlog::info("server bound to {} UDP port", port_number);
  start_receive();
}
