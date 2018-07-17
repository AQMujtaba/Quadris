#include <memory>
#include "tblock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

TBlock::TBlock(shared_ptr<AbstractLevel> level, shared_ptr<Cell> axis,
			   char type = 'T', int orientation = 1) :
	AbstractBlock{ level, axis, type, orientation } {
	height = 3; 
	width = 2; 
}