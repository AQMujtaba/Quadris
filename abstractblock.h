#ifndef _abstractblock_
#define _abstractblock_

#include <memory>
#include "abstractlevel"

class AbstractBlock{
  std::shared_ptr<AbstractLevel> level;
  //std::vector<std::shared_ptr<Cell>> cells; 
  std::shared_ptr<Cell> referenceCell; // lower left cell needed for rotation
  char shape;
  int orientation; // 1 = N, 2 = E, 3 = S, 4 = W
				   // caller's responsibility to cycle from 4 to 1 or 1 to 4
protected:
  int height, width;
  bool placed; // whether or not the block is inactive and placed on grid
  
 public:
  AbstractBlock(std::shared_ptr<AbstractLevel> level,
		 std::shared_ptr<Cell> axis, char type, int orientation);
  int getOrientation() const;
  int& setOrientation();
  std::shared_ptr<AbstractLevel> getLevel();
  std::shared_ptr<Cell> getAxis();
  char getShape() const;
  int getHeight() const;
  int getWidth() const;
  int& setHeight();
  int& setWidth();
  virtual bool isHeavy() const = 0; // true for levels 3+
};

#endif
