#include <iostream>
#include <arpa/inet.h>

#include "base_client.h"

using namespace std;

std::string BaseClient::send_message(const std::string address, const std::string message, const int port)
{
  int socket_desc;
  struct sockaddr_in server;
  char *server_reply = new char[2000];

  socket_desc = socket(AF_INET, SOCK_STREAM, 0);

  if (socket_desc == -1)
  {
    throw "Error creating ocket";
  }

  server.sin_addr.s_addr = inet_addr(address.c_str());
  server.sin_family = AF_INET;
  server.sin_port = htons(port);

  int connected = connect(socket_desc, (struct sockaddr *)&server, sizeof(server));

  if (connected < 0)
  {
    throw "Error connecting to socket";
  }

  int message_sent = write(socket_desc, message.c_str(), strlen(message.c_str()));

  if (message_sent < 0)
  {
    throw "Error sending to socket message";
  } else {
    int message_received = recv(socket_desc, server_reply, 2000, 0);

    if (message_received < 0)
    {
      throw "Error receiving socket message";
    }

    close(socket_desc);
  }

  return server_reply;
}
