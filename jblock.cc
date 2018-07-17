#include <memory>
#include "jblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

JBlock::JBlock(shared_ptr<AbstractLevel> level, shared_ptr<Cell> axis,
			   char type = 'J', int orientation = 1) :
	AbstractBlock{ level, axis, type, orientation } {
	height = 2;
	width = 3;
}