#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(): theDisplay{vector<vector<char>>(18, vector<char>(11, ' '))}{}

void TextDisplay::notify(Subject &whoNotified){
  theDisplay[whoNotified.getRow()][whoNotified.getCol()] = whoNotified.getBlock().getType();
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
