#include <memory>
#include "iblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

IBlock::IBlock(shared_ptr<AbstractLevel> level, shared_ptr<Cell> axis,
			   char type = 'I', int orientation = 1) :
	AbstractBlock{ level, axis, type, orientation } {
	height = 1;
	width = 4;
}