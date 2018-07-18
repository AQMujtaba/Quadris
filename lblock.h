#ifndef _L_BLOCK_
#define _L_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class LBlock : public AbstractBlock {
public:
	LBlock(int level, int col, int row);
	char getShape() const override;
	Coordinates get2ndCell() override;
	Coordinates get3rdCell() override;
	Coordinates get4thCell() override;
};

#endif