#ifndef _abstractlevel_
#define _abstractlevel_

#include <string>
#include <memory>
#include <vector>

class AbstractBlock;

class AbstractLevel {
  int seed;
  bool random;
  std::string seqFile;
  std::vector<char> blockSeq;
 protected:
  int seqPos;
 public:
  AbstractLevel(, bool random, std::string seqFile, int seed = 1);
  ~AbstractLevel();
  bool isRandom();
  void restartSeq();
  void setSeqFile(std::string newFile);
  virtual void setRandom(bool r) = 0;
  virtual int getLevel() = 0;
  virtual std::shared_pointer<AbstractBlock> createBlock() = 0;
};

#endif
