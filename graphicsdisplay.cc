#include "graphicsdisplay.h"
#include <string>

using namespace std;


GraphicsDisplay::GraphicsDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper):
currentLevel{currentLevel}, scoreKeeper{scoreKeeper}, theDisplay{500,800}{
  theDisplay.fillRectangle(0,0,dispWidth,dispHeight,Xwindow::White);
  string levelString = "Level: " + to_string(currentLevel);
  string scoreString = "Score: " + to_string(scoreKeeper->getScore());
  string highScoreString = "Hi-Score: " + to_string(scoreKeeper->getHighScore());
  theDisplay.drawString(20, 20, levelString);
  theDisplay.drawString(20, 40, scoreString);
  theDisplay.drawString(20, 60, highScoreString);
  theDisplay.fillRectangle(20, 100, 460, 620, Xwindow::Black);
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
  if(row >= 3){
    theDisplay.fillRectangle(30 + col*cellSize, 110 + (row-3)*cellSize, cellSize,
                             cellSize, color);
  }
}

void GraphicsDisplay::setLevel(int newLevel){
  currentLevel = newLevel;
}
