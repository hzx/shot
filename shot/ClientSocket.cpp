#include <sys/socket.h>
#include <unistd.h>
#include <memory>
#include "ClientSocket.h"


namespace shot {


ClientSocket::ClientSocket()
    : id(SOCKET_INVALID) {
}


void ClientSocket::read() {
}


void ClientSocket::write() {
}


void ClientSocket::close() {
  ::close(id);
}


void ClientSocket::shutdownRead() {
}


void ClientSocket::shutdownWrite() {
}


void ClientSocket::shutdownReadWrite() {
}


int ClientSocket::getId() const {
  return id;
}


} /* namespace shot */
