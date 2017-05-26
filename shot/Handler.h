#pragma once


namespace shot {


class Handler {
public:
  Handler();
  virtual ~Handler();
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
