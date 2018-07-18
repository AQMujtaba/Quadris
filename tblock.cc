#include <memory>
#include "tblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

TBlock::TBlock(int level, int col, int row) :
	AbstractBlock{ level, col, row } {}

char TBlock::getShape() const {
	return 'T';
}

Coordinates TBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 1, row + 1 };
	return cell;
}

Coordinates TBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col, row + 1 };
	return cell;
}

Coordinates TBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col - 1, row + 1 };
	return cell;
}