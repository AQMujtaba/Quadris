#ifndef _level4_
#define _level4_

#include "abstractlevel.h"
#include <string>
#include <memory>

class AbstractBlock;

class Level4: public AbstractLevel {
public:
  Level4(std::string seqFile = "sequence.txt", int seed = 1);
  void setRandom(bool r) override;
  int getLevel() override;
  std::shared_pointer<AbstractBlock> createBlock() override;
};

#endif
