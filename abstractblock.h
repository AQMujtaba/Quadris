#ifndef _abstractblock_
#define _abstractblock_

#include <memory>
#include "abstractlevel"
#include "coordinates.h"

class AbstractBlock{
  int level; 
  int col, row; // lower left cell needed for rotation
  int orientation; // 1 = N, 2 = E, 3 = S, 4 = W
				           // caller's responsibility to cycle from 4 to 1 or 1 to 4
 public:
  AbstractBlock(int level, int col, int row, int orientation);
  int getOrientation() const;
  void setOrientation(int newOrientation);
  int getLevel();
  int getRow() const;
  int getCol() const;
  void setRow(int newRow);
  void setCol(int newCol);
  bool isHeavy() const; // true for levels 3+
  virtual char getShape() const = 0;
  Coordinates getReference() const;
  virtual Coordinates get2ndCell() = 0;
  virtual Coordinates get3rdCell() = 0;
  virtual Coordinates get4thCell() = 0;
};

#endif