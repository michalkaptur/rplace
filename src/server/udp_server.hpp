#pragma once

#include <array>
#include <boost/asio.hpp>
#include <memory>

using boost::asio::ip::udp;
class udp_server {
public:
  udp_server(boost::asio::io_context &io_context, unsigned port_number);

private:
  void start_receive();

  void handle_receive(const boost::system::error_code &error,
                      std::size_t /*bytes_transferred*/);

  void handle_send(std::shared_ptr<std::string> message,
                   const boost::system::error_code &error,
                   std::size_t bytes_transferred);

  udp::socket socket_;
  udp::endpoint remote_endpoint_;
  std::array<char, 255> recv_buffer_;
};
