#ifndef _grid_
#define _grid_

#include <memory>
#include "abstractblock"

class Grid{
 public:
  Grid();
  void reset();
  void left(AbstractBlock block);
  void right(AbstractBlock block);
  void down(AbstractBlock block);
  void drop(AbstractBlock block);
  void clockwise(AbstractBlock block);
  void counterClockwise(AbstractBlock block);
  void newBlock(AbstractBlock block);
}

#endif
