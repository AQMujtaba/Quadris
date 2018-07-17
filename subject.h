#ifndef _subject_
#define _subject_

#include <vector>

class Observer;

class Subject {
  std::vector<std::shared_ptr<Observer>> observers;
 public:
  void attach(std::shared_ptr<Observer> observer);
  void detach(std::shared_ptr<Observer> observer);
  void notifyObsevers();
  virtual getInfo() const = 0;
}