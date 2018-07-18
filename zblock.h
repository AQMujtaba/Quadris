#ifndef _Z_BLOCK_
#define _Z_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class ZBlock : public AbstractBlock {
public:
	ZBlock(int level, int col, int row);
	char getShape() const override;
	Coordinates get2ndCell() override;
	Coordinates get3rdCell() override;
	Coordinates get4thCell() override;
};

#endif