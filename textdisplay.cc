#include "textdisplay.h"
#include "info.h"

using namespace std;

TextDisplay::TextDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper):
theDisplay{vector<vector<char>>(18, vector<char>(11, ' '))}, currentLevel{currentLevel},
ScoreKeeper{scoreKeeper}{}

void TextDisplay::notify(Subject &whoNotified){
  Info myInfo = whoNotified.getInfo();
  theDisplay[myInfo.row][myInfo.col] = whoNotified.blockType;
}

void TextDisplay::setLevel(int newLevel){
  currentLevel = newLevel;
}

ostream &operater<<ostream &out, const TextDisplay &td){
  out << "Level: " << currentLevel << endl;
  out << "Score: " << scoreKeeper->getScore() << endl;
  out << "Hi-Score: " << scoreKeeper->getHighScore() << endl;
  for(int i = 3; rowIndex < gridHeight; i++){
    for(int j = 0; columnIndex < gridWidth; j++){
      out << td.theDisplay[rowIndex][columnIndex];
    }
    out << endl;
  }
  return out;
}
