#include <memory>
#include "zblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

ZBlock::ZBlock(int level, int col, int row,
std::shared_ptr<ScoreKeeper> score) :
	AbstractBlock{ level, col, row, score } {}

char ZBlock::getShape() const {
	if (hint) {
    return '?';
	} else {
		return 'Z';
	}
}

shared_ptr<AbstractBlock> ZBlock::createHint() const {
	shared_ptr<AbstractBlock> block = make_shared<ZBlock>(level, col, row, score);
	block->toggleHint();
	return block;
}

Coordinates ZBlock::get1stCell(int newOrientation) {
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

Coordinates ZBlock::get2ndCell(int newOrientation) {
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

Coordinates ZBlock::get3rdCell(int newOrientation) {
	int col = getCol();
	int row = getRow();

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4
	
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

	newOrientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
													 // newOrientation % 4

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
	return get1stCell(getOrientation());
}

Coordinates ZBlock::get2ndCell() {
	return get2ndCell(getOrientation());
}

Coordinates ZBlock::get3rdCell() {
	return get3rdCell(getOrientation());
}

Coordinates ZBlock::get4thCell() {
	return get4thCell(getOrientation());
}
