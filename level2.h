#ifndef _level2_
#define _level2_

#include "abstractlevel.h"
#include <string>
#include <memory>

class AbstractBlock;

class Level2: public AbstractLevel {
public:
  Level2(std::string seqFile = "sequence.txt", int seed = 1);
  void setRandom(bool r) override;
  int getLevel() const override;
  std::shared_ptr<AbstractBlock> createBlock() override;
};

#endif


