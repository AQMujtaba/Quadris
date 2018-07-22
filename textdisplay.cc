#include "textdisplay.h"
#include "info.h"

using namespace std;

TextDisplay::TextDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper):
currentLevel{currentLevel}, scoreKeeper{scoreKeeper},
theDisplay{vector<vector<char>>(18, vector<char>(11,' '))}{}

void TextDisplay::notify(Subject &whoNotified){
  Info myInfo = whoNotified.getInfo();
  theDisplay[myInfo.row][myInfo.col] = whoNotified.getInfo().blockType;
}

void TextDisplay::setLevel(int newLevel){
  currentLevel = newLevel;
}

ostream &operator<<(ostream &out, const TextDisplay &td){
  out << "Level: " << td.currentLevel << endl;
  out << "Score: " << td.scoreKeeper->getScore(false) << endl;
  out << "Hi-Score: " << td.scoreKeeper->getHighScore() << endl;
  for(int rowIndex = 3; rowIndex < td.gridHeight; rowIndex++){ 
    for(int columnIndex = 0; columnIndex < td.gridWidth; columnIndex++){ 
      out << td.theDisplay[rowIndex][columnIndex]; 
    }
    out << endl;
  }
  return out;
}
