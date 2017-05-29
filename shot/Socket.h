#pragma once
#include <arpa/inet.h>
#include "ClientSocket.h"


namespace shot {


/**
 * After creation check socket.id != SOCKET_INVALID
 * bind, listen, close return -1 if error
 * after accept check ClientSocket::getId() != SOCKET_INVALID
 */
class Socket {
public:
  Socket();
  ~Socket();
  int bind(int port);
  int listen();
  ClientSocket accept();
  int close();
  int getId() const;
  int getPort() const;
private:
  int id;
  sockaddr_in addr;
  int port;
};


} /* namespace shot */
