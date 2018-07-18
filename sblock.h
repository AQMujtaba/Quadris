#ifndef _S_BLOCK_
#define _S_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class SBlock : public AbstractBlock {
public:
	SBlock(int level, int col, int row);
	char getShape() const override;
	Coordinates get2ndCell() override;
	Coordinates get3rdCell() override;
	Coordinates get4thCell() override;
};

#endif