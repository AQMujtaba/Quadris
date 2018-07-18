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

Coordinates LBlock::get1stCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 2, row };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col + 2, row + 2 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row + 2 };
		return cell;
	} else {
		Coordinates cell{ col, row }; // reference cell is first 'L' cell
		return cell;
	}
}

Coordinates LBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 2, row + 1 };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col + 1, row + 2 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row + 1 };
		return cell;
	} else {
		Coordinates cell{ col + 1, row };
		return cell;
	}
}

Coordinates LBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 2, row + 2 };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col, row + 2 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row }; // reference cell is third 'L' cell
		return cell;				  // when orientation = E
	} else {
		Coordinates cell{ col + 2, row };
		return cell;
	}
}

Coordinates LBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 1, row + 2 };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col, row + 1 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else {
		Coordinates cell{ col + 2, row + 1 };
		return cell;
	}
}