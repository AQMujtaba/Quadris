#include <memory>
#include "zblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

ZBlock::ZBlock(int level, int col, int row, int height = 2) :
	AbstractBlock{ level, col, row, height } {}

char ZBlock::getShape() const {
	return 'Z';
}

Coordinates ZBlock::get1stCell(int newOrientation) {
	int col = getCol();
	int row = getRow();
	if (newOrientation == 3) {
		Coordinates cell{ col + 1, row - 1 };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col + 1, row - 1 };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col, row - 1 };
		return cell;
	} else {
		Coordinates cell{ col + 1, row }; 
		return cell;
	}
}

Coordinates ZBlock::get2ndCell(int newOrientation) {
	int col = getCol();
	int row = getRow();
	if (newOrientation == 3) {
		Coordinates cell{ col + 1, row - 2 };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col, row - 1 };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col, row };
		return cell;
	} else {
		Coordinates cell{ col + 2, row }; 
		return cell;
	}
}

Coordinates ZBlock::get3rdCell(int newOrientation) {
	int col = getCol();
	int row = getRow();
	if (newOrientation == 3) {
		Coordinates cell{ col, row - 1 };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col + 1, row - 1 };
		return cell;
	} else {
		Coordinates cell{ col + 1, row - 1 }; 
		return cell;
	}
}

Coordinates ZBlock::get4thCell(int newOrientation) {
	int col = getCol();
	int row = getRow();
	if (newOrientation == 3) {
		Coordinates cell{ col, row };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col + 2, row };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col + 1, row - 2 };
		return cell;
	} else {
		Coordinates cell{ col, row - 1 }; 
		return cell;
	}
}
Coordinates ZBlock::get1stCell() {
	return get1stCell(orientation);
}

Coordinates ZBlock::get2ndCell() {
	return get2ndCell(orientation);
}

Coordinates ZBlock::get3rdCell() {
	return get3rdCell(orientation);
}

Coordinates ZBlock::get4thCell() {
	return get4thCell(orientation);
}