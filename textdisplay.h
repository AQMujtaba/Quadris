#ifndef _TEXT_DISPLAY_H
#define _TEXT_DISPLAY_H

#include <iostream>
#include <vector>
#include <memory>
#include "observer.h"
#include "scoreKeeper.h"

class TextDisplay: public Observer {
  int currentLevel;
  std::shared_ptr<ScoreKeeper> scoreKeeper;
  std::vector<std::vector<char>> theDisplay;
 public:
  TextDisplay(std::shared_ptr<AbstractLevel> currentLevel);
  void notify(Subject &whoNotified) override;
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
