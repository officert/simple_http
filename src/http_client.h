#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "base_client.h"

class HttpClient : public BaseClient  {
  public:
    void get(const char *);
};

#endif
