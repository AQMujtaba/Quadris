#include <memory>
#include "iblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

IBlock::IBlock(int level, int col, int row) :
	AbstractBlock{ level, col, row } {}

char IBlock::getShape() const {
	return 'I';
}

Coordinates IBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 1, row };
	return cell;
}

Coordinates IBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 2, row };
	return cell;
}

Coordinates IBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	Coordinates cell{ col + 3, row };
	return cell;
}