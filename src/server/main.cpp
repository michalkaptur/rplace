#include "map.hpp"
#include "udp_server.hpp"
#include <boost/asio.hpp>
#include <csignal>
#include <spdlog/spdlog.h>

void handler(const boost::system::error_code &error, int signal_number) {
  spdlog::warn("rplace server signalled #{} [{}]", signal_number,
               error.message());
  if (signal_number == SIGINT or signal_number == SIGTERM) {
    spdlog::info("exiting gracefully");
    exit(0);
  }
  exit(1);
}

int main() {
  spdlog::set_level(spdlog::level::trace); // TODO: parametrize log level
  spdlog::info("rplace server is starting up");
  boost::asio::io_context io_context;
  boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);
  signals.async_wait(handler);
  // TODO parametrize size
  constexpr auto size = 16;
  auto map = make_map(size);
  udp_server server(io_context, 4545, map); // TODO: parametrize port
  io_context.run();
  spdlog::info("rplace server is shutting down");
  return 0;
}
