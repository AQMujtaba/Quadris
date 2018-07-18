#ifndef _graphicsdisplay_
#define _graphicsdisplay_

#include <string>
#include "observer.h"
#include "window.h"

class GraphicsDisplay: public Observer{
  Xwindow theDisplay;
 public:
  GraphicsDisplay();
  
  void notify(Subject<Info, State> &whoNotified) override;
  
  //Think About how to update scoreboard at top.
};

#endif
