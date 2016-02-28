#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "base_client.h"

class HttpClient : public BaseClient  {
  public:
    char* get(const char *);
};

#endif
