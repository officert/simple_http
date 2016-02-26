#ifndef BASECLIENT_H
#define BASECLIENT_H

class BaseClient {
  protected:
    void send_message(const char* address, const char* message, const int port);
};

#endif
