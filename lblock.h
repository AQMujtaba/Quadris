#ifndef _L_BLOCK_
#define _L_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class LBlock : public AbstractBlock {
public:
LBlock(std::shared_ptr<AbstractLevel> level, std::shared_ptr<Cell> axis,
	   char type = 'L', int orientation = 1);
};

#endif