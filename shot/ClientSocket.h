#pragma once
#include <arpa/inet.h>


namespace shot {


class ClientSocket {
public:
  ClientSocket();
  void read();
  void write();
  void close();
  void shutdownRead();
  void shutdownWrite();
  void shutdownReadWrite();
  int getId() const;
private:
  int id;
  sockaddr addr;
  socklen_t addrSize;
  friend class Socket;
};


const int SOCKET_INVALID = -1;
const int PORT_RESERVED = 0;


} /* namespace shot */
