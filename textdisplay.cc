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

void TextDisplay::updateNextBlock(char type) {
  nextBlockType = type;
}

ostream &operator<<(ostream &out, const TextDisplay &td){
  out.fill(' ');
  out.width(15);
  out << left << "Level:";
  out << right << td.currentLevel << endl;
  out.width(15);
  out << left << "Score:";
  out << right << td.scoreKeeper->getScore(false) << endl;
  out.width(15);
  out << left << "Hi-Score:";
  out << right << td.scoreKeeper->getHighScore() << endl;
  for(int rowIndex = 3; rowIndex < td.gridHeight; rowIndex++){ 
    for(int columnIndex = 0; columnIndex < td.gridWidth; columnIndex++){ 
      out << td.theDisplay[rowIndex][columnIndex]; 
    }
    out << endl;
  }
  out << "Next:" << endl;

  if(td.nextBlockType == 'I'){
    out << "IIII" << endl;
  }
  else if(td.nextBlockType == 'J'){
    out << "J" << endl << "JJJ" << endl;
  }
  else if(td.nextBlockType == 'L'){
    out << "  L" << endl << "LLL" << endl;
  }
  else if(td.nextBlockType == 'O'){
    out << "OO" << endl << "OO" << endl;
  }
  else if(td.nextBlockType == 'S'){
    out << " SS" << endl << "SS " << endl;
  }
  else if(td.nextBlockType == 'T'){
    out << "TTT" << endl << " T " << endl;
  }
  else if(td.nextBlockType == 'Z'){
    out << "ZZ " << endl << " ZZ" << endl;
  }
  return out;
}
