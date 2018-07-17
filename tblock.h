#ifndef _T_BLOCK_
#define _T_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class TBlock : public AbstractBlock {
public:
TBlock(std::shared_ptr<AbstractLevel> level, std::shared_ptr<Cell> axis,
	   char type = 'T', int orientation = 1);
};

#endif