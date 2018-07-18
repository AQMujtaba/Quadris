#ifndef _grid_
#define _grid_

#include <memory>
#include <vector>
#include "abstractblock"

class Cell;
class GraphicsDisplay;
class TextDisplay;

class Grid{
  const int gridHeight = 18;
  const int gridWidth = 11;
  int currentLevel;
  std::vector<std::vector<Cell>> theGrid;
  std::shared_ptr<TextDisplay> td;
  std::shared_ptr<GraphicsDisplay> gd;
  std::shared_ptr<ScoreKeeper> scoreKeeper;
  
  void checkRows();
  void clearRow(int row);
  void shiftRowsDown(int startRow);
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
  void replaceBlock(std::shared_ptr<AbstractBlock> currBlock,
                    std::shared_ptr<AbstractBlock> newBlock);
}

#endif
