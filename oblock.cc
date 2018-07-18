#include <memory>
#include "oblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

OBlock::OBlock(int level, int col, int row) :
	AbstractBlock{ level, col, row } {}

char OBlock::getShape() const {
	return 'O';
}

Coordinates OBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 1, row };
	return cell;
}

Coordinates OBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 1, row + 1 };
	return cell;
}

Coordinates OBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col, row + 1 };
	return cell;
}