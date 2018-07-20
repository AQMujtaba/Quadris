#ifndef _subject_
#define _subject_

#include <vector>
#include <memory>
#include "info.h"

class Observer;

class Subject {
  std::vector<std::shared_ptr<Observer>> observers;
 public:
  void attach(std::shared_ptr<Observer> observer);
  void detach(std::shared_ptr<Observer> observer);
  void notifyObservers();
  virtual Info getInfo() const = 0;
};

#endif
