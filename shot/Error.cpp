#include "Error.h"


namespace shot {


Error::Error()
    : status(ErrorStatus::OK) {
}


bool Error::isBad() {
  return status != ErrorStatus::OK;
}


void Error::setError(ErrorStatus status_) {
  status = status_;
}


} /* namespace shot */
