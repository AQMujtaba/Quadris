#include "textdisplay.h"
#include "info.h"

using namespace std;

TextDisplay::TextDisplay(int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper):
theDisplay{vector<vector<char>>(18, vector<char>(11, ' '))}, currentLevel{currentLevel},
scoreKeeper{scoreKeeper}{}

void TextDisplay::notify(Subject &whoNotified){
  Info myInfo = whoNotified.getInfo();
  theDisplay[myInfo.row][myInfo.col] = whoNotified.getInfo().blockType;
}

void TextDisplay::setLevel(int newLevel){
  currentLevel = newLevel;
}

ostream &operator<<(ostream &out, const TextDisplay &td){
  out << "Level: " << td.currentLevel << endl;
  out << "Score: " << td.scoreKeeper->getScore() << endl;
  out << "Hi-Score: " << td.scoreKeeper->getHighScore() << endl;
  for(int i = 3; rowIndex < td.gridHeight; i++){ // ****** "rowIndex undefined"
    for(int j = 0; columnIndex < td.gridWidth; j++){ // ******** "columnIndex undefined"
      out << td.theDisplay[rowIndex][columnIndex]; // ***** ^
    }
    out << endl;
  }
  return out;
}
