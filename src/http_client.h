#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "base_client.h"

class HttpClient : public BaseClient  {
  public:
    std::string get(const std::string);
};

#endif
