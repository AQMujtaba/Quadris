#ifndef _abstractlevel_
#define _abstractlevel_

#include "abstractblock"

class AbstractLevel {
 public:
  virtual AbstractBlock createBlock() = 0;
}

#endif
