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

Coordinates SBlock::get1stCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col + 2, row + 1 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row + 2 };
		return cell;
	} else {
		Coordinates cell{ col, row }; 
		return cell;
	}
}

Coordinates SBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 2, row + 1};
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

Coordinates SBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col + 1, row + 1 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row + 1 };
		return cell;
	} else {
		Coordinates cell{ col, row }; 
		return cell;
	}
}

Coordinates SBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col + 1, row + 1 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row + 1 };
		return cell;
	} else {
		Coordinates cell{ col, row }; 
		return cell;
	}
}