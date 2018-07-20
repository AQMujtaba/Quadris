#include "cell.h"
#include "subject.h"
#include "abstractblock.h"

using namespace std;

Cell::Cell(int row, int col): row{row}, col{col}, block{nullptr}{}

int Cell::getRow() const {
  return row;
}

int Cell::getCol() const {
  return col;
}

shared_ptr<AbstractBlock> Cell::getBlock() const{
  return block;
}
void Cell::setBlock(shared_ptr<AbstractBlock> newBlock){
  if(canAddBlock(newBlock)){
    block = newBlock;
    notifyObservers();
  }
}

bool Cell::isEmpty() const{
  if(block == nullptr){
    return true;
  }
  return false;
}

bool Cell::canAddBlock(shared_ptr<AbstractBlock> newBlock) const{
  if(block == nullptr || block == newBlock){
    return true;
  }
  return false;
}

void Cell::clearCell() {
  block = nullptr;
  notifyObservers();
}

Info Cell::getInfo() const {
  Info myInfo;
  myInfo.col = col;
  myInfo.row = row;
  if(block){
    myInfo.blockType = block->getShape();
  }
  else{
    myInfo.blockType = ' ';
  }
  return myInfo;
}
