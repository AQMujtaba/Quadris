#ifndef _observer_
#define _observer_

class Subject;

class Observer {
  virtual void notify(Subject &whoFrom) = 0;
  virtual ~Observer = default;
};

#endif
