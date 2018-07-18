#ifndef _grid_
#define _grid_

#include <memory>
#include <vector>
#include "abstractblock"

class Cell;
class GraphicsDisplay;
class TextDisplay;

class Grid{
  int currentLevel;
  std::vector<std::vector<Cell>> theGrid;
  std::shared_ptr<TextDisplay> td;
  std::shared_ptr<GraphicsDisplay> gd;
 public:
  Grid(std::shared_ptr<AbstractLevel> currentLevel = nullptr);
  void hint();
  void reset();
  void left(std::shared_ptr<AbstractBlock> block, int multiplicity);
  void right(std::shared_ptr<AbstractBlock> block, int multiplicity);
  void down(std::shared_ptr<AbstractBlock> block, int multiplicity);
  void drop(std::shared_ptr<AbstractBlock> block);
  void clockwise(std::shared_ptr<AbstractBlock> block, int multiplicity);
  void counterClockwise(std::shared_ptr<AbstractBlock> block, int multiplicity);
  void newBlock(std::shared_ptr<AbstractBlock> block);
  void setLevel(std::shared_ptr<AbstractLevel> newLevel);
}

#endif
