#ifndef _graphicsdisplay_
#define _graphicsdisplay_

#include <string>
#include <memory>
#include "observer.h"
#include "window.h"
#include "scorekeeper.h"
#include "cell.h"


class GraphicsDisplay: public Observer{
  const int dispHeight = 800;
  const int dispWidth = 500;
  int currentLevel;
  std::shared_ptr<ScoreKeeper> scoreKeeper;
  
  Xwindow theDisplay;
 public:
  GraphicsDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper);
  ~GraphicsDisplay() = default;
  void notify(Subject &whoNotified) override;
  
  void setLevel(int newLevel);
  //Think About how to update scoreboard at top.
};

#endif
