#ifndef _abstractblock_
#define _abstractblock_

#include <memory>
#include "abstractlevel.h"
#include "coordinates.h"

class ScoreKeeper;

class AbstractBlock{
  int level; 
  std::shared_ptr<ScoreKeeper> score;
  bool placed;
  int col, row; // lower left cell needed for rotation
  int orientation; // 0 = N, 1 = E, 2 = S, 3 = W
 protected:
  bool hint;
 public:
  AbstractBlock(int level, int col, int row, 
    std::shared_ptr<ScoreKeeper> score);
  ~AbstractBlock();
  int getOrientation() const;
  void setOrientation(int newOrientation);
  void togglePlaced(); // toggle placement off
  void toggleHint(); // toggle hint between on and off
  int getLevel();
  int getRow() const;
  int getCol() const;
  void setRow(int newRow);
  void setCol(int newCol);
  void setScoreKeeper(std::shared_ptr<ScoreKeeper> newScore);
  bool isHeavy() const; // true for levels 3+
  Coordinates getReference() const;
  virtual char getShape() const = 0;
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
