#ifndef _subject_
#define _subject_

#include <vector>

class Observer;

class Subject {
  std::vector<shared_ptr<Observer>> observers;
 public:
  void attach(shared_ptr<Observer> observer);
  void notifyObsevers();
  virtual getInfo() const = 0;
}
