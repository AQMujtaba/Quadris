#ifndef _L_BLOCK_
#define _L_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "abstractlevel.h"
#include "cell.h"

class LBlock : public AbstractBlock {
public:
	LBlock(int level, int col, int row,
		std::shared_ptr<ScoreKeeper> score, int height = 2);
	char getShape() const override;
	Coordinates get1stCell() override;
	Coordinates get2ndCell() override;
	Coordinates get3rdCell() override;
	Coordinates get4thCell() override;
	Coordinates get1stCell(int newOrientation) override; 
  	Coordinates get2ndCell(int newOrientation) override; 
  	Coordinates get3rdCell(int newOrientation) override;
  	Coordinates get4thCell(int newOrientation) override;
};

#endif