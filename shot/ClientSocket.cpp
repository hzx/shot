#include <sys/socket.h>
#include <unistd.h>
#include <memory>
#include "ClientSocket.h"


namespace shot {


ClientSocket::ClientSocket()
    : id(SOCKET_INVALID) {
}


ClientSocket::~ClientSocket() {
  close();
}


// TODO(dem): implement read
void ClientSocket::read() {
}


// TODO(dem): implement write
void ClientSocket::write() {
}


int ClientSocket::close() {
  if (id == SOCKET_INVALID) return 0;
  return ::close(id);
}


int ClientSocket::shutdownRead() {
  return ::shutdown(id, SHUT_RD);
}


int ClientSocket::shutdownWrite() {
  return ::shutdown(id, SHUT_WR);
}


int ClientSocket::shutdownReadWrite() {
  return ::shutdown(id, SHUT_RDWR);
}


int ClientSocket::getId() const {
  return id;
}


} /* namespace shot */
