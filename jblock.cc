#include <memory>
#include "jblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

JBlock::JBlock(int level, int col, int row) :
	AbstractBlock{ level, col, row } {}

char JBlock::getShape() const {
	return 'J';
}

Coordinates JBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 1, row };
	return cell;
}

Coordinates JBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 2, row };
	return cell;
}

Coordinates JBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col, row + 1 };
	return cell;
}