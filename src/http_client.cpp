#include <iostream>
#include <arpa/inet.h>

#include "http_client.h"

using namespace std;

void HttpClient::get(const char *address)
{
  const char* message = "GET / HTTP/1.1\r\n\r\n";
  const int port = 80;

  if (address == NULL)
  {
    throw "address cannot be null";
  }

  cout << "HTTP GET" << endl;
  cout << "Send to " << address << endl;

  this->create_socket(address, message, port);
}
