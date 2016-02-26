#include <iostream>
#include <arpa/inet.h>

#include "base_client.h"

using namespace std;

//Functions prototypes
int connectToSocket(int socketDesc, struct sockaddr_in *socketAddr, socklen_t addressLength);

void BaseClient::create_socket(const char* address)
{
  if (address == NULL)
  {
    throw "address cannot be null";
  }

  int socket_desc;
  struct sockaddr_in server;
  const char *message;
  char server_reply[2000];

  socket_desc = socket(AF_INET, SOCK_STREAM, 0);

  if (socket_desc == -1)
  {
    printf("Could not create socket\n");
  } else {
    printf("Socket created\n");
  }

  server.sin_addr.s_addr = inet_addr(address);
  server.sin_family = AF_INET;
  server.sin_port = htons(80);

  int connected = connectToSocket(socket_desc, &server, sizeof(server));

  message = "GET / HTTP/1.1\r\n\r\n";

  int messageSent = write(socket_desc, message, strlen(message));

  if (messageSent < 0) {
    puts("Send failed");
  } else {
    puts("Data Sent\n");

    int messageReceived = read(socket_desc, server_reply, 2000);

    if (messageReceived < 0) {
      puts("recv failed");
    } else {
      puts("Reply received\n");
      puts(server_reply);
    }

    close(socket_desc);
  }
}

int connectToSocket(int socketDesc, struct sockaddr_in *socketAddr, socklen_t addressLength) {
  int connected = connect(socketDesc, (struct sockaddr *)socketAddr, addressLength);

  if(connected >= 0) {
    puts("Connected");
  } else {
    puts("Error connecting");
  }

  return connected;
}
