#ifndef BASECLIENT_H
#define BASECLIENT_H

class BaseClient {
  protected:
    std::string send_message(const std::string address, const std::string message, const int port);
};

#endif
