#include "singleblock.h"
#include <memory>
#include "abstractblock.h"
#include "cell.h"

using namespace std;

SingleBlock::SingleBlock(int level, int col, int row,
std::shared_ptr<ScoreKeeper> score) :
	AbstractBlock{ level, col, row, score} {}

char SingleBlock::getShape() const {
	return '*';
}

Coordinates SingleBlock::get1stCell(){
  return Coordinates{getCol(), getRow()};
}

Coordinates SingleBlock::get2ndCell(){
  return Coordinates{getCol(), getRow()};
}

Coordinates SingleBlock::get3rdCell(){
  return Coordinates{getCol(), getRow()};
}

Coordinates SingleBlock::get4thCell(){
  return Coordinates{getCol(), getRow()};
}

Coordinates SingleBlock::get1stCell(int newOrientation){
  (void)newOrientation;
  return Coordinates{getCol(), getRow()};
}

Coordinates SingleBlock::get2ndCell(int newOrientation){
  (void)newOrientation;
  return Coordinates{getCol(), getRow()};
}

Coordinates SingleBlock::get3rdCell(int newOrientation){
  (void)newOrientation;
  return Coordinates{getCol(), getRow()};
}

Coordinates SingleBlock::get4thCell(int newOrientation){
  (void)newOrientation;
  return Coordinates{getCol(), getRow()};
}
