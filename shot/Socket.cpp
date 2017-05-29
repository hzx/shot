#include <sys/socket.h>
#include <stdio.h>
/* #include <sys/epoll.h> */
#include <unistd.h>
#include <memory.h>
#include <memory>
#include "Socket.h"


namespace shot {


Socket::Socket()
    : port(PORT_RESERVED) {
  memset(&addr, 0, sizeof(sockaddr_in));

  // TODO(dem): SOCK_NONBLOCK is epoll flag, figure out which flag in kqueue
  id = socket(AF_INET, SOCK_STREAM /*| SOCK_NONBLOCK*/, 0);
}


Socket::~Socket() {
  close();
}


int Socket::bind(int port_) {
  port = port_;

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  // set reuse option
  int optionValue = 1;
  setsockopt(id, SOL_SOCKET, SO_REUSEADDR,
      reinterpret_cast<void*>(&optionValue), sizeof(optionValue));

  return ::bind(id, reinterpret_cast<sockaddr*>(&addr), sizeof(sockaddr));
}


int Socket::listen() {
  return ::listen(id, 1);
}


ClientSocket Socket::accept() {
  ClientSocket client;

  client.id = ::accept(id, &client.addr, &client.addrSize);

  return client;
}


int Socket::close() {
  return ::close(id);
}


int Socket::getId() const {
  return id;
}


int Socket::getPort() const {
  return port;
}

  
} /* namespace shot */
