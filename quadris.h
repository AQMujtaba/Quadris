#ifndef _quadris_
#define _quadris_

#include <iostream>
#include <memory>
#include <string>
#include "grid.h"
#include "AbstractBlock.h"
#include "commandinterpreter.h"

class Quadris {
  int seed;
  bool textOnly;
  std::string seqFile;
  std::unique_ptr<Grid> theGrid;
  std::shared_ptr<ScoreKeeper> scoreKeeper;
  std::shared_ptr<AbstractBlock> currentBlock;
  std::shared_ptr<AbstractLevel> currentLevel;
  std::unique_ptr<CommandInterpreter> commandInterpreter;
  
  void setLevel(int level);
 public:
  Quadris(bool textOnly, int seed, std::string seqFile, int startLevel);
  void start();
};

#endif
