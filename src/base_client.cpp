#include <iostream>
#include <arpa/inet.h>

#include "base_client.h"

using namespace std;

char* BaseClient::send_message(const char* address, const char* message, const int port)
{
  if (address == NULL)
  {
    throw "address cannot be null";
  }
  if (message == NULL)
  {
    throw "message cannot be null";
  }

  int socket_desc;
  struct sockaddr_in server;
  char *server_reply = new char[2000];

  socket_desc = socket(AF_INET, SOCK_STREAM, 0);

  if (socket_desc == -1)
  {
    throw "Error creating ocket";
  }

  server.sin_addr.s_addr = inet_addr(address);
  server.sin_family = AF_INET;
  server.sin_port = htons(port);

  int connected = connect(socket_desc, (struct sockaddr *)&server, sizeof(server));

  if (connected < 0)
  {
    throw "Error connecting to socket";
  }

  int message_sent = write(socket_desc, message, strlen(message));

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
