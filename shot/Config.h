#pragma once
#include <string>
#include <unordered_set>


namespace shot {
  

class Config {
public:
  Config(const std::string& filename);

  std::string filename;
  int port;
  std::string cookieSecret;
  size_t bufferSize;
  std::unordered_set<std::string> allowOrigins;
};


} /* namespace shot */
