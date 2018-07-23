#ifndef _T_BLOCK_
#define _T_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class TBlock : public AbstractBlock {
public:
	TBlock(int level, int col, int row,
		std::shared_ptr<ScoreKeeper> score);
	char getShape() const override;
	std::shared_ptr<AbstractBlock> createHint() override;
	Coordinates get1stCell(int newOrientation) override; 
  	Coordinates get2ndCell(int newOrientation) override; 
  	Coordinates get3rdCell(int newOrientation) override;
  	Coordinates get4thCell(int newOrientation) override;
  	Coordinates get1stCell() override;
	Coordinates get2ndCell() override;
	Coordinates get3rdCell() override;
	Coordinates get4thCell() override;
};

#endif
