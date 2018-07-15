#ifndef _abstractblock_
#define _abstractblock_

#include <memory>
#include "abstractlevel"

class AbstractBlock{
  shared_ptr{AbstractLevel} level;
 public:
  AbstractBlock();
};

#endif
