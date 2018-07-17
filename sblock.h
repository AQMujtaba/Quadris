#ifndef _S_BLOCK_
#define _S_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class SBlock : public AbstractBlock {
public:
SBlock(std::shared_ptr<AbstractLevel> level, std::shared_ptr<Cell> axis,
	   char type = 'S', int orientation = 1);
};

#endif