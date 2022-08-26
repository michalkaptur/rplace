#include "udp_server.hpp"
#include "protocol/ping.hpp"
#include <json_serializer/pong.hpp>
#include <json_serializer/serializer.hpp>

template <class Callable> struct message_handler {
  explicit message_handler(Callable send) : send(send){};

  void operator()(const protocol::Ping &msg) {
    auto resp = protocol::json_serializer::serialize(
        protocol::Pong{.greeting = msg.greeting});
    send(std::make_shared<std::string>(resp));
  }

private:
  Callable send;
};

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
    std::cout << "received message\n";
    auto decoded_request = protocol::json_serializer::deserialize(request);
    // FIXME: nested lambdas below aren't that readable
    auto send = [this](std::shared_ptr<std::string> response) {
      this->socket_.async_send_to(boost::asio::buffer(*response),
                                  this->remote_endpoint_,
                                  [this, response](auto err, auto bytes_tx) {
                                    this->handle_send(response, err, bytes_tx);
                                  });
    };
    message_handler handler(send);
    std::visit(handler, decoded_request);

    // auto response = std::make_shared<std::string>("bar");
    // socket_.async_send_to(boost::asio::buffer(*response), remote_endpoint_,
    //                       [this, response](auto err, auto bytes_tx) {
    //                         this->handle_send(response, err, bytes_tx);
    //                       });

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
