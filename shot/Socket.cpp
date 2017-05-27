#include <sys/socket.h>
#include <unistd.h>
#include <memory>
#include "Socket.h"


namespace shot {


Socket::Socket()
    : id(SOCKET_INVALID) {
}


void Socket::bind() {
}


void Socket::listen() {
}


void Socket::accept(ClientSocket& client) {
}


void Socket::close() {
  ::close(id);
}


int Socket::getId() const {
  return id;
}

  
} /* namespace shot */
