#pragma once
#include "Config.h"
#include "Request.h"
#include "RequestParser.h"
#include "Response.h"
#include "Router.h"
#include "Socket.h"
#include "ClientSocket.h"
#include "EventPoll.h"


namespace shot {


class Server {
public:
  void wait();
  void process();
private:
  Socket socket;
  EventPoll eventPoll;
  RequestParser requestParser;
};

  
} /* namespace shot */
