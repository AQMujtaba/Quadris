#ifndef _Z_BLOCK_
#define _Z_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class ZBlock : public AbstractBlock {
public:
ZBlock(std::shared_ptr<AbstractLevel> level, std::shared_ptr<Cell> axis,
	   char type = 'Z', int orientation = 1);
};

#endif