#ifndef _level3_
#define _level3_

#include "abstractlevel.h"
#include <string>
#include <memory>

class AbstractBlock;

class Level3: public AbstractLevel {
public:
  Level3(std::string seqFile = "sequence.txt", int seed = 1);
  void setRandom(bool r) override;
  int getLevel() override;
  std::shared_pointer<AbstractBlock> createBlock() override;
};

#endif



