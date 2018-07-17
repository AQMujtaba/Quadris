#ifndef _O_BLOCK_
#define _O_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class OBlock : public AbstractBlock {
public:
OBlock(std::shared_ptr<AbstractLevel> level, std::shared_ptr<Cell> axis,
	   char type = 'O', int orientation = 1);
};

#endif