#ifndef _level0_
#define _level0_

#include "abstractlevel.h"
#include <string>
#include <memory>

class AbstractBlock;

class Level0: public AbstractLevel {
 public:
  Level0(std::string seqFile);
  void setRandom(bool r) override;
  int getLevel() override;
  std::shared_ptr<AbstractBlock> createBlock() override;
};

#endif
