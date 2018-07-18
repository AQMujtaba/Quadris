#include <memory>
#include "zblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

ZBlock::ZBlock(int level, int col, int row) :
	AbstractBlock{ level, col, row } {}

char ZBlock::getShape() const {
	return 'Z';
}

Coordinates ZBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 1, row };
	return cell;
}

Coordinates ZBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col, row + 1 };
	return cell;
}

Coordinates ZBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col - 1, row + 1 };
	return cell;
}