#include <memory>
#include "abstractblock.h"
#include "cell.h"
#include "abstractlevel.h"

using namespace std;

AbstractBlock::AbstractBlock(shared_ptr<AbstractLevel> level,
	shared_ptr<Cell> axis, char type, int orientation) :
	level{ level }, referenceCell{ axis }, shape{ type },
	orientation{ orientation } {}

int AbstractBlock::getOrientation() const {
	return orientation;
}
int& AbstractBlock::setOrientation() {
	return orientation;
}
shared_ptr<AbstractLevel> AbstractBlock::getLevel() {
	return level;
}
shared_ptr<Cell> AbstractBlock::getAxis() {
	return referenceCell;
}
char AbstractBlock::getShape() const {
	return shape;
}
int AbstractBlock::getHeight() const {
	return height;
}
int AbstractBlock::getWidth() const {
	return width;
}
int& AbstractBlock::setHeight() {
	return height;
}
int& AbstractBlock::setWidth() {
	return width;
}
	