#ifndef _quadris_
#define _quadris_

#include <iostream>
#include <memory>
#include <string>
#include "grid.h"
#include "scorekeeper.h"
#include "abstractblock.h"
#include "commandinterpreter.h"

class Quadris {
  int seed;
  std::string seqFile;
  std::unique_ptr<Grid> theGrid;
  std::unique_ptr<CommandInterpreter> myInterpreter;
  std::shared_ptr<ScoreKeeper> scoreKeeper;
  std::shared_ptr<AbstractBlock> currentBlock;
  std::shared_ptr<AbstractBlock> nextBlock;
  std::shared_ptr<AbstractLevel> currentLevel;
  void setLevel(int level);
 public:
  Quadris(bool textOnly, int seed, std::string seqFile, int startLevel);
  void Start();
};

#endif
