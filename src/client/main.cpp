#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;
int main() {
  boost::asio::io_service io_service;
  udp::socket socket{io_service};
  socket.open(udp::v4());
  udp::endpoint receiver_endpoint(boost::asio::ip::make_address_v4("127.0.0.1"),
                                  4545); // FIXME don't hardcode
  std::array<char, 1> send_buf = {{0}};
  socket.send_to(boost::asio::buffer(send_buf), receiver_endpoint);
  boost::array<char, 128> recv_buf;
  udp::endpoint sender_endpoint;
  size_t len =
      socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);

  return len;
}
