#pragma once
#include <arpa/inet.h>
/* #include <sys/socket.h> */


namespace shot {


class ClientSocket {
public:
  ClientSocket();
  void read();
  void write();
  void close();
  int getId() const;
private:
  int id;
  sockaddr addr;
  friend class Socket;
};


const int SOCKET_INVALID = -1;


} /* namespace shot */
