#include "udp_server.hpp"

void udp_server::start_receive() {
  socket_.async_receive_from(
      boost::asio::buffer(recv_buffer_), remote_endpoint_,
      [this](auto err, auto rx_bytes) { this->handle_receive(err, rx_bytes); });
}
void udp_server::handle_receive(const boost::system::error_code &error,
                                std::size_t /*bytes_transferred*/) {
  if (!error) {
    std::cout << "received message\n";
    auto message = std::make_shared<std::string>("bar");
    socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
                          [this, message](auto err, auto bytes_tx) {
                            this->handle_send(message, err, bytes_tx);
                          });

    //   start_receive(); //terminate after first msg received, just to test
    //   without graceful shutdown
  }
}
void udp_server::handle_send(std::shared_ptr<std::string> message,
                             const boost::system::error_code &error,
                             std::size_t bytes_transferred) {
  if (!error) {
    std::cout << "message sent [" << *message << ", " << bytes_transferred
              << " bytes]\n";
  } else {
    std::cout << "failed to send message\n";
  }
}
udp_server::udp_server(boost::asio::io_context &io_context)
    : socket_(io_context, udp::endpoint(udp::v4(), 4545)) { // TODO: parametrize
  start_receive();
}
