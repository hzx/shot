#pragma once
#include <string>


namespace shot {


enum class ErrorStatus: uint32_t {
  OK = 0,
};


class Error {
public:
  Error();
  bool isBad();
  void setError(ErrorStatus status);
private:
  ErrorStatus status;
};


} /* namespace shot */
