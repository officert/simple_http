#include <iostream>
#include <arpa/inet.h>

#include "http_client.h"

using namespace std;

char* HttpClient::get(const char *address)
{
  const char* message = "GET / HTTP/1.1\r\n\r\n";
  const int port = 80;
  char* response;

  if (address == NULL)
  {
    throw "address cannot be null";
  }

  // cout << "HTTP GET" << endl;
  // cout << "Send to " << address << endl;

  response = this->send_message(address, message, port);

  return response;
}
