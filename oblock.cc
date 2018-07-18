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

Coordinates OBlock::get1stCell() {
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
		Coordinates cell{ col, row }; // reference cell is first 'O' cell
		return cell;
	}
}

Coordinates OBlock::get2ndCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col + 1, row + 1 };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col, row + 1 };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col, row };
		return cell;
	} else {
		Coordinates cell{ col + 1, row };
		return cell;
	}
}

Coordinates OBlock::get3rdCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col, row + 1 };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col, row };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else {
		Coordinates cell{ col + 1, row + 1 }; 
		return cell;
	}
}

Coordinates OBlock::get4thCell() {
	int col = getCol();
	int row = getRow();
	if (orientation == 3) {
		Coordinates cell{ col, row };
		return cell;
	} else if (orientation == 2) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else if (orientation == 1) {
		Coordinates cell{ col + 1, row + 1 };
		return cell;
	} else {
		Coordinates cell{ col, row + 1 };
		return cell;
	}
}