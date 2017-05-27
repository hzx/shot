#include <unistd.h>
#include "EventPoll.h"


namespace shot {


EventPoll::EventPoll()
    : id(0) {
}


void EventPoll::close() {
  ::close(id);
}


} /* namespace shot */
