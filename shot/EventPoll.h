#pragma once


namespace shot {


class EventPoll {
public:
  EventPoll();
  void close();
private:
  int id;
};


} /* namespace shot */
