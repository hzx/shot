#pragma once
#include <string>


namespace shot {


class Logger {
public:
  void info(const std::string& message);
  void warning(const std::string& message);
  void error(const std::string& message);
private:
};

  
} /* namespace shot */
