#include "graphicsdisplay.h"
#include <string>

using namespace std;

GraphicsDisplay::GraphicsDisplay(int n): theDisplay{((500/n)*n), ((500/n)*n)}, gridSize{n}{
  
}

GraphicsDisplay::GraphicsDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper):
theDisplay{500,800},currentLevel{currentLevel}, ScoreKeeper{scoreKeeper}{
  theDisplay.fillRectangle(0,0,dispWidth,dispHeight,Xwindow::White);
  string levelString = "Level: " + currentLevel;
  string scoreString = "Score: " + scoreKeeper.getScore();
  string highScoreString = "Hi-Score: " + scoreKeeper.getHighScore();
  theDisplay.drawBigString(20, 20, levelString);
  theDisplay.drawBigString(20, 40, scoreString);
  theDisplay.drawBigString(20, 60, highScoreString);
  theDisplay.drawRectangle(20, 100, 460, 620, Xwindow::Black);
  theDisplay.drawRectangle(30, 110, 440, 600, Xwindow::White);
}

void GraphicsDisplay::redraw(int n){
  int dispSize = (500/gridSize) * gridSize;
  theDisplay.fillRectangle(0, 0, dispSize, dispSize, Xwindow::Blue);
  gridSize = n;
}


void GraphicsDisplay::notify(Cell &whoNotified){
  int cellSize = 40;
  int row = whoNotified.getRow();
  int col = whoNotified.getCol();
  
  //Reprint scores/level if they change.
  
  if(whoNotified.getBlock() == nullptr){
    theDisplay.drawRectangle(30 + col*cellSize, 110 + row*cellSize, cellSize,
                             cellSize, Xwindow::White);
  }
  else{
    char shape = whoNotified.getBlock().getShape();
    int color
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
    else{
      color = Xwindow::Brown;
    }
    theDisplay.drawRectangle(30 + col*cellSize, 110 + row*cellSize, cellSize,
                             cellSize, color);
  }
}

void GraphicsDisplay::gameOver(string s){
  theDisplay.fillRectangle(195, 140, 110, 50, Xwindow::Red);
  theDisplay.fillRectangle(200, 145, 100, 40, Xwindow::White);
  theDisplay.drawString(210, 160, s);
}
