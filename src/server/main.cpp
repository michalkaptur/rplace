#include "udp_server.hpp"
#include <boost/asio.hpp>
#include <spdlog/spdlog.h>

int main() {
  spdlog::set_level(spdlog::level::trace); //TODO: parametrize log level
  spdlog::info("rplace server is starting up");
  boost::asio::io_context io_context;
  udp_server server(io_context, 4545); // TODO: parametrize port
  io_context.run();
  spdlog::info("rplace server is shutting down");
  return 0;
}