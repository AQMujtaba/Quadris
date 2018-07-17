#ifndef _J_BLOCK_
#define _J_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class JBlock : public AbstractBlock {
public:
JBlock(std::shared_ptr<AbstractLevel> level, std::shared_ptr<Cell> axis,
	   char type = 'J', int orientation = 1);
};

#endif