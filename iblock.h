#ifndef _I_BLOCK_
#define _I_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class IBlock : public AbstractBlock {
public:
IBlock(std::shared_ptr<AbstractLevel> level, std::shared_ptr<Cell> axis,
	   char type = 'I', int orientation = 1);
};

#endif