#include <memory>
#include "oblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

OBlock::OBlock(shared_ptr<AbstractLevel> level, shared_ptr<Cell> axis,
			   char type = 'O', int orientation = 1) :
	AbstractBlock{ level, axis, type, orientation } {
	height = 2;
	width = 2;
}