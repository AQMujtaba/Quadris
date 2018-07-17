#include <memory>
#include "sblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

SBlock::SBlock(shared_ptr<AbstractLevel> level, shared_ptr<Cell> axis,
			   char type = 'S', int orientation = 1) :
	AbstractBlock{ level, axis, type, orientation } {
	height = 2; // ?
	width = 2; // ?
}