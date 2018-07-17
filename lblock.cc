#include <memory>
#include "lblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

LBlock::LBlock(shared_ptr<AbstractLevel> level, shared_ptr<Cell> axis,
			   char type = 'L', int orientation = 1) :
	AbstractBlock{ level, axis, type, orientation } {
	height = 2;
	width = 3;
}