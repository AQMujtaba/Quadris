#include <memory>
#include "lblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

LBlock::LBlock(int level, int col, int row) :
	AbstractBlock{ level, col, row } {}

char LBlock::getShape() const {
	return 'L';
}

Coordinates LBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 1, row };
	return cell;
}

Coordinates LBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 2, row };
	return cell;
}

Coordinates LBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 2, row + 1 };
	return cell;
}