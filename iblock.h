#ifndef _I_BLOCK_
#define _I_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class IBlock : public AbstractBlock {
public:
	IBlock(int level, int col, int row);
	char getShape() const override;
	Coordinates get1stCell() override;
	Coordinates get2ndCell() override;
	Coordinates get3rdCell() override;
	Coordinates get4thCell() override;
};

#endif