#include "graphicsdisplay.h"
#include <string>

using namespace std;


GraphicsDisplay::GraphicsDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper):
currentLevel{currentLevel}, scoreKeeper{scoreKeeper}, theDisplay{500,800}{
  cerr << "done MIL for GD, starting body" << endl;
  theDisplay.fillRectangle(0,0,dispWidth,dispHeight,Xwindow::White);
  cerr << "line 1 done" << endl;
  string levelString = "Level: " + to_string(currentLevel);
  cerr << "line 2 done" << endl;
  string scoreString = "Score: " + to_string(scoreKeeper->getScore());
  cerr << "line 3 done" << endl;
  string highScoreString = "Hi-Score: " + to_string(scoreKeeper->getHighScore());
  cerr << "line 4 done" << endl;
  theDisplay.drawString(20, 20, levelString);
  cerr << "line 5 done" << endl;
  theDisplay.drawString(20, 40, scoreString);
  cerr << "line 6 done" << endl;
  theDisplay.drawString(20, 60, highScoreString);
  cerr << "line 7 done" << endl;
  theDisplay.fillRectangle(20, 100, 460, 620, Xwindow::Black);
  cerr << "line 8 done" << endl;
  theDisplay.fillRectangle(30, 110, 440, 600, Xwindow::White);
}

void GraphicsDisplay::notify(Subject &whoNotified){
  Info myInfo = whoNotified.getInfo();
  int cellSize = 40;
  int row = myInfo.row;
  int col = myInfo.col;
  
  //Reprint scores/level if they change find a better way 2 do this
  string levelString = "Level: " + to_string(currentLevel);
  string scoreString = "Score: " + to_string(scoreKeeper->getScore());
  string highScoreString = "Hi-Score: " + to_string(scoreKeeper->getHighScore());
  
  char shape = myInfo.blockType;
  int color;
  if(shape == 'I'){
    color = Xwindow::Red;
  }
  else if(shape == 'J'){
    color = Xwindow::Green;
  }
  else if(shape == 'L'){
    color = Xwindow::Blue;
  }
  else if(shape == 'O'){
    color = Xwindow::Cyan;
  }
  else if(shape == 'S'){
    color = Xwindow::Yellow;
  }
  else if(shape == 'T'){
    color = Xwindow::Magenta;
  }
  else if(shape == 'Z'){
    color = Xwindow::Orange;
  }
  else if(shape == '*'){
    color = Xwindow::Brown;
  }
  else{
    color = Xwindow::White;
  }
  theDisplay.fillRectangle(30 + col*cellSize, 110 + row*cellSize, cellSize,
                           cellSize, color);
}

void GraphicsDisplay::setLevel(int newLevel){
  currentLevel = newLevel;
}
