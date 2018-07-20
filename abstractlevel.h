#ifndef _abstractlevel_
#define _abstractlevel_

#include <string>
#include <memory>
#include <vector>

class AbstractBlock;

class AbstractLevel {
  std::string seqFile;
 protected:
  int seed;
  std::vector<char> blockSeq;
  bool random;
  int seqPos;
 public:
  AbstractLevel(bool random, std::string seqFile, int seed = 1);
  ~AbstractLevel();
  bool isRandom();
  void setSeqFile(std::string newFile);
  virtual void setRandom(bool r) = 0;
  virtual int getLevel() = 0;
  virtual std::shared_ptr<AbstractBlock> createBlock() = 0;
};

#endif
