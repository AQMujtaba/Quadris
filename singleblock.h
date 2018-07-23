#ifndef _SINGLE_BLOCK_
#define _SINGLE_BLOCK_

#include <memory>
#include "abstractblock.h"
#include "cell.h"

class SingleBlock: public AbstractBlock {
public:
	SingleBlock(int level, int col, int row,
		std::shared_ptr<ScoreKeeper> score);
	char getShape() const override;
  std::shared_ptr<AbstractBlock> createHint() override;
  Coordinates get1stCell(int newOrientation) override; // cells with
  Coordinates get2ndCell(int newOrientation) override; // simulated
  Coordinates get3rdCell(int newOrientation) override; // orientation
  Coordinates get4thCell(int newOrientation) override;
  Coordinates get1stCell() override;
  Coordinates get2ndCell() override;
  Coordinates get3rdCell() override;
  Coordinates get4thCell() override;
};

#endif
