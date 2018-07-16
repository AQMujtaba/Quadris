#ifndef _grid_
#define _grid_

#include <memory>
#include <vector>
#include "abstractblock"

class Cell;
class GraphicsDisplay;
class TextDisplay;

class Grid{
  std::vector<std::vector<Cell>> theGrid;
  shared_ptr<TextDisplay> td;
  shared_ptr<GraphicsDisplay> gd;
 public:
  Grid();
  void hint();
  void reset();
  void left(std::shared_ptr<AbstractBlock> block);
  void right(std::shared_ptr<AbstractBlock> block);
  void down(std::shared_ptr<AbstractBlock> block);
  void drop(std::shared_ptr<AbstractBlock> block);
  void clockwise(std::shared_ptr<AbstractBlock> block);
  void counterClockwise(std::shared_ptr<AbstractBlock> block);
  void newBlock(std::shared_ptr<AbstractBlock> block);
}

#endif
