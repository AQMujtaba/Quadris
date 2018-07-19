#ifndef _abstractblock_
#define _abstractblock_

#include <memory>
#include "abstractlevel"
#include "coordinates.h"

class AbstractBlock{
  int level; 
  int height; // height at initial orientation
  int col, row; // lower left cell needed for rotation
  int orientation; // 0 = N, 1 = E, 2 = S, 3 = W
				           // caller's responsibility to cycle from 3 to 0 or 0 to 3
 public:
  AbstractBlock(int level, int col, int row, int orientation, int height);
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
  virtual Coordinates get1stCell() = 0;
  virtual Coordinates get2ndCell() = 0;
  virtual Coordinates get3rdCell() = 0;
  virtual Coordinates get4thCell() = 0;
  virtual Coordinates get1stCell(int newOrientation) = 0; // cells with 
  virtual Coordinates get2ndCell(int newOrientation) = 0; // simulated 
  virtual Coordinates get3rdCell(int newOrientation) = 0; // orientation
  virtual Coordinates get4thCell(int newOrientation) = 0;

};

#endif