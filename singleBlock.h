#ifndef _SINGLE_BLOCK_
#define _SINGLE_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class SingleBlock : public AbstractBlock {
public:
	SingleBlock(int level, int col, int row,
		std::shared_ptr<ScoreKeeper> score, int height = 1);
	char getShape() const override;
};

#endif