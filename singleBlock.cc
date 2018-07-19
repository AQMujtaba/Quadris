#include <memory>
#include "singleBlock.h"
#include "abstractblock.h"
#include "cell.h"

using namespace std;

SingleBlock::SingleBlock(int level, int col, int row,
std::shared_ptr<ScoreKeeper> score, int height = 1) :
	AbstractBlock{ level, col, row, score, height } {}

char SingleBlock::getShape() const {
	return '*';
}

