#ifndef _TEXT_DISPLAY_H
#define _TEXT_DISPLAY_H

#include <iostream>
#include <vector>
#include <memory>
#include "observer.h"
#include "scorekeeper.h"

class TextDisplay: public Observer {
  const int gridHeight = 18;
  const int gridWidth = 11;
  int currentLevel;
  char nextBlockType;
  std::shared_ptr<ScoreKeeper> scoreKeeper;
  std::vector<std::vector<char>> theDisplay;
 public:
  TextDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper);
  void notify(Subject &whoNotified) override;
  void setLevel(int newLevel);
  void updateNextBlock(char type);
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
