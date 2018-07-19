#ifndef _graphicsdisplay_
#define _graphicsdisplay_

#include <string>
#include "observer.h"
#include "window.h"

class GraphicsDisplay: public Observer{
  const int gridHeight = 18;
  const int gridWidth = 11;
  const int dispHeight = 800;
  csont int dispWidth = 500;
  int currentLevel;
  std::shared_ptr<ScoreKeeper> scoreKeeper;
  
  Xwindow theDisplay;
 public:
  GraphicsDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper);
  
  void notify(Subject<Info, State> &whoNotified) override;
  
  //Think About how to update scoreboard at top.
};

#endif
