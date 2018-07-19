#ifndef _observer_
#define _observer_

#include "subject.h"

class Observer {
 public:
  virtual void notify(Subject &whoFrom) = 0;
  virtual ~Observer() = default;
};

#endif
