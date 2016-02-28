#include <iostream>
#include <arpa/inet.h>

#include "http_client.h"

using namespace std;

std::string HttpClient::get(const std::string address)
{
  const std::string message = "GET / HTTP/1.1\r\n\r\n";
  const int port = 80;
  std::string response;

  response = this->send_message(address, message, port);

  return response;
}
