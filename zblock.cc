#include <memory>
#include "zblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

ZBlock::ZBlock(shared_ptr<AbstractLevel> level, shared_ptr<Cell> axis,
			   char type = 'Z', int orientation = 1) :
	AbstractBlock{ level, axis, type, orientation } {
	height = 2; // ?
	width = 2; // ?
}