#ifndef _J_BLOCK_
#define _J_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class JBlock : public AbstractBlock {
public:
	JBlock(int level, int col, int row);
	char getShape() const override;
	Coordinates get2ndCell() override;
	Coordinates get3rdCell() override;
	Coordinates get4thCell() override;
};

#endif