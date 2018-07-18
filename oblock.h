#ifndef _O_BLOCK_
#define _O_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class OBlock : public AbstractBlock {
public:
	OBlock(int level, int col, int row);
	char getShape() const override;
	Coordinates get1stCell() override;
	Coordinates get2ndCell() override;
	Coordinates get3rdCell() override;
	Coordinates get4thCell() override;
};


#endif