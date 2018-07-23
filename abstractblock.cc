#include <memory>
#include "abstractblock.h"
#include "cell.h"
#include "abstractlevel.h"
#include "scorekeeper.h"

using namespace std;

AbstractBlock::AbstractBlock(int level, int col, int row,
	shared_ptr<ScoreKeeper> score):
	level{ level }, score{ score }, col{ col }, row{ row } {
	orientation = 0;
	placed = true;
	hint = false;
}

AbstractBlock::~AbstractBlock() {
	if (placed) {
		int points = ((level + 1) * (level + 1));
    if(!score){
    }
		score->addScore(points);
	}
} 

int AbstractBlock::getOrientation() const {
	return orientation;
}

void AbstractBlock::setOrientation(int newOrientation) {
	orientation = ((newOrientation % 4 + 4) % 4); // math equivalent to 
												  // newOrientation % 4
}

void AbstractBlock::togglePlaced() {
	placed = false;
}

void AbstractBlock::toggleHint() {
	hint = true;
	placed = false;
}

int AbstractBlock::getLevel() {
	return level;
}
int AbstractBlock::getRow() const {
	return row;
}
int AbstractBlock::getCol() const {
	return col;
}
void AbstractBlock::setRow(int newRow) {
	row = newRow;
}
void AbstractBlock::setCol(int newCol) {
	col = newCol;
}

void AbstractBlock::setScoreKeeper(std::shared_ptr<ScoreKeeper> newScore){
  score = newScore;
}


bool AbstractBlock::isHeavy() const {
	return (level >= 3);
}

int AbstractBlock::getHeight() {
	int row1 = get1stCell().row;
 	int row2 = get2ndCell().row;
  	int row3 = get3rdCell().row;
  	int row4 = get4thCell().row;
	int height = row - row1;

	((row - row2) > height ? height = row - row2: height);  	
	((row - row3) > height ? height = row - row3: height);
	((row - row4) > height ? height = row - row4: height);

	return height;
}

Coordinates AbstractBlock::getReference() const {
	Coordinates cell{ col, row };
	return cell;
}
