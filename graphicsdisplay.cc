#include "graphicsdisplay.h"
#include <string>

using namespace std;


GraphicsDisplay::GraphicsDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper):
currentLevel{currentLevel}, scoreKeeper{scoreKeeper}, theDisplay{500, 800}{
  theDisplay.fillRectangle(0,0,dispWidth,dispHeight,Xwindow::White);
  string levelString = "Level: " + to_string(currentLevel);
  string scoreString = "Score: " + to_string(scoreKeeper->getScore(true));
  string highScoreString = "Hi-Score: " + to_string(scoreKeeper->getHighScore());
  theDisplay.drawString(300, 20, "Next Block:");
  theDisplay.drawString(20, 20, levelString);
  theDisplay.drawString(20, 40, scoreString);
  theDisplay.drawString(20, 60, highScoreString);
  theDisplay.fillRectangle(20, 120, 460, 620, Xwindow::Black);
  theDisplay.fillRectangle(30, 130, 440, 600, Xwindow::White);
}

void GraphicsDisplay::drawNext(){
  theDisplay.fillRectangle(300, 30, 200 , 80, Xwindow:: White);
  if(nextBlockType == 'J'){
    theDisplay.fillRectangle(300, 30, 40, 40, Xwindow::Green);
    theDisplay.fillRectangle(300, 70, 120, 40, Xwindow::Green);
  }
  else if(nextBlockType == 'L'){
    theDisplay.fillRectangle(380, 30, 40, 40, Xwindow::Blue);
    theDisplay.fillRectangle(300, 70, 120, 40, Xwindow::Blue);
  }
  else if(nextBlockType == 'I'){
    theDisplay.fillRectangle(300, 30, 160, 40, Xwindow::Red);
  }
  else if(nextBlockType == 'O'){
    theDisplay.fillRectangle(300, 30, 80, 80, Xwindow::Cyan);
  }
  else if(nextBlockType == 'S'){
    theDisplay.fillRectangle(340, 30, 80, 40, Xwindow::Yellow);
    theDisplay.fillRectangle(300, 70, 80, 40, Xwindow::Yellow);
  }
  else if(nextBlockType == 'T'){
    theDisplay.fillRectangle(300, 30, 120, 40, Xwindow::Magenta);
    theDisplay.fillRectangle(340, 70, 40, 40, Xwindow::Magenta);
  }
  else if(nextBlockType == 'Z'){
    theDisplay.fillRectangle(300, 30, 80, 40, Xwindow::Orange);
    theDisplay.fillRectangle(340, 70, 80, 40, Xwindow::Orange);
  }
}

void GraphicsDisplay::notify(Subject &whoNotified){
  Info myInfo = whoNotified.getInfo();
  int cellSize = 40;
  int row = myInfo.row;
  int col = myInfo.col;
  //Reprint scores/level if they change find a better way 2 do this
  if(scoreKeeper->getHasChanged()){
    string scoreString = "Score: " + to_string(scoreKeeper->getScore(true));
    string highScoreString = "Hi-Score: " + to_string(scoreKeeper->getHighScore());
    theDisplay.fillRectangle(20,30,480,40,Xwindow::White);
    theDisplay.drawString(20, 40, scoreString);
    theDisplay.drawString(20, 60, highScoreString);
  }
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
  else if(shape == '?'){
    color = Xwindow::Black;
  }
  else{
    color = Xwindow::White;
  }

  if(row >= 3){
    theDisplay.fillRectangle(30 + col*cellSize, 130 + (row-3)*cellSize, cellSize,
                             cellSize, color);
  }
}

void GraphicsDisplay::updateNextBlock(char type) {
  nextBlockType = type;
  drawNext();
}

void GraphicsDisplay::setLevel(int newLevel){
  currentLevel = newLevel;
  string levelString = "Level: " + to_string(currentLevel);
  theDisplay.fillRectangle(20,10,480,20,Xwindow::White);
  theDisplay.drawString(20, 20, levelString);
}
