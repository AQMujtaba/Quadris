#ifndef _cell_
#define _cell_

class Observer;
class Subject;
class AbstractBlock;

class Cell: public Subject {
  const int row, col;
  std::shared_ptr<AbstractBlock> block;
 public:
  Cell(int row, int col);
  int getRow() const;
  int getCol() const;
  std::shared_ptr<AbstractBlock> getBlock() const;
  void setBlock(std::shared_ptr<AbstractBlock> newBlock);
  bool isEmpty() const;
  bool canAddBlock(std::shared_ptr<AbstractBlock> newBlock) const;
  void clearCell(bool withScore);
};

#endif
