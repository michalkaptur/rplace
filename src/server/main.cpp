#include <array>
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;
class udp_server {
public:
  udp_server(boost::asio::io_context &io_context)
      : socket_(io_context,
                udp::endpoint(udp::v4(), 4545)) { // TODO: parametrize
    start_receive();
  }

private:
  void start_receive() {
    socket_.async_receive_from(boost::asio::buffer(recv_buffer_),
                               remote_endpoint_,
                               [this](auto err, auto rx_bytes) {
                                 this->handle_receive(err, rx_bytes);
                               });
  }

  void handle_receive(const boost::system::error_code &error,
                      std::size_t bytes_transferred) {
    if (!error) {
      for (unsigned i = 0; i < bytes_transferred; i++) {
        std::cout << recv_buffer_[i];
      }
      //   start_receive(); //terminate after first msg received, just to test
      //   without graceful shutdown
    }
  }

  void handle_send(boost::shared_ptr<std::string> /*message*/,
                   const boost::system::error_code & /*error*/,
                   std::size_t /*bytes_transferred*/) {}

  udp::socket socket_;
  udp::endpoint remote_endpoint_;
  std::array<char, 255> recv_buffer_;
};

int main() {
  boost::asio::io_context io_context;
  udp_server server(io_context);
  io_context.run();
  return 0;
}