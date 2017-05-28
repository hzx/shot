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
  if (id == SOCKET_INVALID) {
    // TODO(dem): report error
  }
}


Socket::~Socket() {
  close();
}


void Socket::bind(int port_) {
  port = port_;

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  // set reuse option
  int optionValue = 1;
  setsockopt(id, SOL_SOCKET, SO_REUSEADDR,
      reinterpret_cast<void*>(&optionValue), sizeof(optionValue));

  if (::bind(id, reinterpret_cast<sockaddr*>(&addr), sizeof(sockaddr)) == -1) {
    // TODO(dem): report error
  }
}


void Socket::listen() {
  if (::listen(id, 1) == -1) {
    // TODO(dem): report error
  }
}


ClientSocket Socket::accept() {
  ClientSocket client;

  client.id = ::accept(id, &client.addr, &client.addrSize);

  return client;
}


void Socket::close() {
  ::close(id);
}


int Socket::getId() const {
  return id;
}


int Socket::getPort() const {
  return port;
}

  
} /* namespace shot */
