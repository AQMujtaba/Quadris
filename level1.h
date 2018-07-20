#ifndef _level1_
#define _level1_

#include "abstractlevel.h"
#include <string>
#include <memory>

class AbstractBlock;

class Level1: public AbstractLevel {
public:
  Level1(std::string seqFile = "sequence.txt", int seed = 1);
  void setRandom(bool r) override;
  int getLevel() override;
  std::shared_ptr<AbstractBlock> createBlock() override;
};

#endif

