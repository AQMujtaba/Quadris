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

Coordinates IBlock::get1stCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 3, row };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col + 3, row + 3 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row + 3};
		return cell;
	} else {
		Coordinates cell{ col, row };
		return cell;
	}
}

Coordinates IBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 3, row + 1 };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col + 2, row + 3 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row + 2 };
		return cell;
	} else {
		Coordinates cell{ col + 1, row };
		return cell;
	}
}


Coordinates IBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 3, row + 1 };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col + 1, row + 3 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row + 1 };
		return cell;
	} else {
		Coordinates cell{ col + 2, row };
		return cell;
	}
}


Coordinates IBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 3, row };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col, row + 3 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row };
		return cell;
	} else {
		Coordinates cell{ col + 3, row };
		return cell;
	}


}