#include <iostream>
#include <arpa/inet.h>

#include "base_client.h"
#include "http_client.h"

using namespace std;

void HttpClient::get(const char *address)
{
  if (address == NULL)
  {
    throw "address cannot be null";
  }

  cout << "HTTP GET" << endl;
  cout << "Send to " << address << endl;
}
