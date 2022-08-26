#include "udp_server.hpp"
#include <boost/asio.hpp>

int main() {
  boost::asio::io_context io_context;
  udp_server server(io_context);
  io_context.run();
  return 0;
}