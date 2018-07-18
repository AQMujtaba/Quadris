#include <memory>
#include "sblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

SBlock::SBlock(int level, int col, int row) :
	AbstractBlock{ level, col, row } {}

char SBlock::getShape() const {
	return 'S';
}

Coordinates SBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 1, row };
	return cell;
}

Coordinates SBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 2, row + 1 };
	return cell;
}

Coordinates SBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 1, row + 1 };
	return cell;
}