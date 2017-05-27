#pragma once


namespace shot {


class RequestHandler {
public:
  RequestHandler();
  virtual ~RequestHandler();
  virtual void get();
  virtual void xget();
  virtual void post();
  virtual void xpost();
  virtual void put();
  virtual void xput();
  virtual void del();
  virtual void xdel();
private:
};

  
} /* namespace shot */
