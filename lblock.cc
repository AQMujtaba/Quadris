#include <memory>
#include "lblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

LBlock::LBlock(int level, int col, int row,
std::shared_ptr<ScoreKeeper> score) :
	AbstractBlock{ level, col, row, score } {}

char LBlock::getShape() const {
	if (hint) {
    return '?';
	} else {
		return 'L';
	}
}

shared_ptr<AbstractBlock> LBlock::createHint() {
	shared_ptr<AbstractBlock> block = make_shared<LBlock>(getLevel(), 
										getCol(), getRow(), nullptr);
	block->toggleHint();
	return block;
}

Coordinates LBlock::get1stCell(int newOrientation) {
	int col = getCol();
	int row = getRow();

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4

	if (newOrientation == 3) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col + 2, row - 1 };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col, row - 2 };
		return cell;
	} else {
		Coordinates cell{ col, row };
		return cell;
	}
}

Coordinates LBlock::get2ndCell(int newOrientation) {
	int col = getCol();
	int row = getRow();

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4

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

Coordinates LBlock::get3rdCell(int newOrientation) {
	int col = getCol();
	int row = getRow();

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4

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

Coordinates LBlock::get4thCell(int newOrientation) {
	int col = getCol();
	int row = getRow();

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4
	
	if (newOrientation == 3) {
		Coordinates cell{ col, row - 2 };
		return cell;
	} else if (newOrientation == 2) {
		Coordinates cell{ col, row };
		return cell;
	} else if (newOrientation == 1) {
		Coordinates cell{ col + 1, row };
		return cell;
	} else {
		Coordinates cell{ col + 2, row - 1 };
		return cell;
	}
}
Coordinates LBlock::get1stCell() {
	return get1stCell(getOrientation());
}

Coordinates LBlock::get2ndCell() {
	return get2ndCell(getOrientation());
}

Coordinates LBlock::get3rdCell() {
	return get3rdCell(getOrientation());
}

Coordinates LBlock::get4thCell() {
	return get4thCell(getOrientation());
}
