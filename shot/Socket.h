#pragma once
#include <arpa/inet.h>
#include "ClientSocket.h"


namespace shot {


class Socket {
public:
  Socket();
  ~Socket();
  void bind(int port);
  void listen();
  ClientSocket accept();
  void close();
  int getId() const;
  int getPort() const;
private:
  int id;
  sockaddr_in addr;
  int port;
};


} /* namespace shot */
