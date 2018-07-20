#include "grid.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"

using namespace std;

void Grid::checkRows(){
  int clearCount = 0;
  for(int rowIndex = gridHeight-1; rowIndex > 0; rowIndex--){
    bool allFilled = true;
    for(int colIndex = 0; colIndex < gridWidth; colIndex++){
      if(theGrid[rowIndex][colIndex].getBlock() == nullptr){
        allFilled = false;
      }
    }
    if(allFilled){
      clearRow(rowIndex);
      shiftRowsDown(rowIndex);
      rowIndex++;
      clearCount++;
    }
  }
  int scoreToAdd = currentLevel + clearCount;
  scoreToAdd *= scoreToAdd;
  scoreKeeper->addScore(scoreToAdd);
}

void Grid::clearRow(int row){
  for(int colIndex = 0; colIndex < gridWidth; colIndex++){
    theGrid[row][colIndex].clearCell();
  }
}

void Grid::shiftRowsDown(int startRow){
  if(startRow > 0){
    for(int colIndex = 0; colIndex < gridWidth; colIndex++){
      shared_ptr<AbstractBlock> newBlock = theGrid[startRow-1][colIndex].getBlock();
      if(newBlock != nullptr){
        theGrid[startRow][colIndex].setBlock(newBlock);
        theGrid[startRow-1][colIndex].clearCell();
      }
    }
    shiftRowsDown(startRow - 1);
  }
}

void Grid::dropSingleBlock(){
  // ***** Implement when Single Block is implemented
}

Grid::Grid(bool textOnly, int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper): textOnly{textOnly}, currentLevel{currentLevel}, td{make_shared<TextDisplay>(currentLevel, scoreKeeper)}, gd{textOnly ? nullptr : make_shared<GraphicsDisplay>(currentLevel, scoreKeeper)}{
  for(int rowIndex = 0; rowIndex < gridHeight; rowIndex++){
    vector<Cell> rowVec;
    for(int colIndex = 0; colIndex < gridWidth; colIndex++){
      rowVec.emplace_back(Cell{rowIndex, colIndex});
      rowVec[colIndex].attach(td);
      if(!textOnly){
        rowVec[colIndex].attach(gd);
      }
    }
    theGrid.push_back(rowVec);
  }
}

void Grid::hint(){
  
}

void Grid::reset(){
  for(int rowIndex = 0; rowIndex < 11; rowIndex++){
    for(int colIndex = 0; colIndex < gridHeight; colIndex++){
      theGrid[rowIndex][colIndex].clearCell();
    }
  }
}

void Grid::left(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity; i++){
    Coordinates c1 = block->get1stCell();
    Coordinates c2 = block->get2ndCell();
    Coordinates c3 = block->get3rdCell();
    Coordinates c4 = block->get4thCell();
    
    if(c1.col > 0 && c2.col > 0
       && c3.col > 0 && c4.col > 0){
      if(theGrid[c1.row][c1.col - 1].canAddBlock(block)
         && theGrid[c2.row][c2.col - 1].canAddBlock(block)
         && theGrid[c3.row][c3.col - 1].canAddBlock(block)
         && theGrid[c4.row][c4.col - 1].canAddBlock(block)){
        theGrid[c1.row][c1.col].clearCell();
        theGrid[c2.row][c2.col].clearCell();
        theGrid[c3.row][c3.col].clearCell();
        theGrid[c4.row][c4.col].clearCell();
        theGrid[c1.row][c1.col - 1].setBlock(block);
        theGrid[c2.row][c2.col - 1].setBlock(block);
        theGrid[c3.row][c3.col - 1].setBlock(block);
        theGrid[c4.row][c4.col - 1].setBlock(block);
        block->setCol(block->getCol() - 1);
      }
    }
  }
  if(block->getLevel() >= 3){
    down(block, 1);
  }
}

void Grid::right(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity; i++){
    Coordinates c1 = block->get1stCell();
    Coordinates c2 = block->get2ndCell();
    Coordinates c3 = block->get3rdCell();
    Coordinates c4 = block->get4thCell();
    
    if(c1.col < 10 && c2.col < 10
       && c3.col < 10 && c4.col < 10){
      if(theGrid[c1.row][c1.col + 1].canAddBlock(block)
         && theGrid[c2.row][c2.col + 1].canAddBlock(block)
         && theGrid[c3.row][c3.col + 1].canAddBlock(block)
         && theGrid[c4.row][c4.col + 1].canAddBlock(block)){
        theGrid[c1.row][c1.col].clearCell();
        theGrid[c2.row][c2.col].clearCell();
        theGrid[c3.row][c3.col].clearCell();
        theGrid[c4.row][c4.col].clearCell();
        theGrid[c1.row][c1.col + 1].setBlock(block);
        theGrid[c2.row][c2.col + 1].setBlock(block);
        theGrid[c3.row][c3.col + 1].setBlock(block);
        theGrid[c4.row][c4.col + 1].setBlock(block);
        block->setCol(block->getCol() + 1);
      }
    }
  }
  if(block->getLevel() >= 3){
    down(block, 1);
  }
}

void Grid::down(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity; i++){
    Coordinates c1 = block->get1stCell();
    Coordinates c2 = block->get2ndCell();
    Coordinates c3 = block->get3rdCell();
    Coordinates c4 = block->get4thCell();
    
    if(c1.row < gridHeight - 1 && c2.row < gridHeight - 1
       && c3.row < gridHeight - 1 && c4.row < gridHeight - 1){
      if(theGrid[c1.row + 1][c1.col].canAddBlock(block)
         && theGrid[c2.row + 1][c2.col].canAddBlock(block)
         && theGrid[c3.row + 1][c3.col].canAddBlock(block)
         && theGrid[c4.row + 1][c4.col].canAddBlock(block)){
        theGrid[c1.row][c1.col].clearCell();
        theGrid[c2.row][c2.col].clearCell();
        theGrid[c3.row][c3.col].clearCell();
        theGrid[c4.row][c4.col].clearCell();
        theGrid[c1.row + 1][c1.col].setBlock(block);
        theGrid[c2.row + 1][c2.col].setBlock(block);
        theGrid[c3.row + 1][c3.col].setBlock(block);
        theGrid[c4.row + 1][c4.col].setBlock(block);
        block->setRow(block->getRow() + 1);
      }
    }
  }
}

void Grid::drop(std::shared_ptr<AbstractBlock> block){
  int prevRow = 0;
  int newRow = 1;
  while(prevRow < newRow){
    prevRow = block->getRow();
    down(block, 1);
    newRow = block->getRow();
  }
  checkRows();
}

void Grid::clockwise(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity; i++){
    Coordinates c1 = block->get1stCell();
    Coordinates c2 = block->get2ndCell();
    Coordinates c3 = block->get3rdCell();
    Coordinates c4 = block->get4thCell();
    Coordinates newc1 = block->get1stCell(block->getOrientation() + 1);
    Coordinates newc2 = block->get2ndCell(block->getOrientation() + 1);
    Coordinates newc3 = block->get3rdCell(block->getOrientation() + 1);
    Coordinates newc4 = block->get4thCell(block->getOrientation() + 1);
    
    if(newc1.col < gridWidth && newc2.col < gridWidth
       && newc3.col < gridWidth && newc4.col < gridWidth){
      if(theGrid[newc1.row][newc1.col].canAddBlock(block)
         && theGrid[newc2.row][newc2.col].canAddBlock(block)
         && theGrid[newc3.row][newc3.col].canAddBlock(block)
         && theGrid[newc4.row][newc4.col].canAddBlock(block)){
        theGrid[c1.row][c1.col].clearCell();
        theGrid[c2.row][c2.col].clearCell();
        theGrid[c3.row][c3.col].clearCell();
        theGrid[c4.row][c4.col].clearCell();
        theGrid[newc1.row][newc1.col].setBlock(block);
        theGrid[newc2.row][newc2.col].setBlock(block);
        theGrid[newc3.row][newc3.col].setBlock(block);
        theGrid[newc4.row][newc4.col].setBlock(block);
        block->setOrientation(block->getOrientation() + 1);
      }
    }
  }
}

void Grid::counterClockwise(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity; i++){
    Coordinates c1 = block->get1stCell();
    Coordinates c2 = block->get2ndCell();
    Coordinates c3 = block->get3rdCell();
    Coordinates c4 = block->get4thCell();
    Coordinates newc1 = block->get1stCell(block->getOrientation() - 1);
    Coordinates newc2 = block->get2ndCell(block->getOrientation() - 1);
    Coordinates newc3 = block->get3rdCell(block->getOrientation() - 1);
    Coordinates newc4 = block->get4thCell(block->getOrientation() - 1);
    
    if(newc1.col < gridWidth && newc2.col < gridWidth
       && newc3.col < gridWidth && newc4.col < gridWidth){
      if(theGrid[newc1.row][newc1.col].canAddBlock(block)
         && theGrid[newc2.row][newc2.col].canAddBlock(block)
         && theGrid[newc3.row][newc3.col].canAddBlock(block)
         && theGrid[newc4.row][newc4.col].canAddBlock(block)){
        theGrid[c1.row][c1.col].clearCell();
        theGrid[c2.row][c2.col].clearCell();
        theGrid[c3.row][c3.col].clearCell();
        theGrid[c4.row][c4.col].clearCell();
        theGrid[newc1.row][newc1.col].setBlock(block);
        theGrid[newc2.row][newc2.col].setBlock(block);
        theGrid[newc3.row][newc3.col].setBlock(block);
        theGrid[newc4.row][newc4.col].setBlock(block);
        block->setOrientation(block->getOrientation() - 1);
      }
    }
  }
}

bool Grid::newBlock(std::shared_ptr<AbstractBlock> block){
  if((blocksSinceClear % 5 == 0) && (blocksSinceClear != 0) && (currentLevel == 4)){
    dropSingleBlock();
  }
  
  if(block->getShape() == 'I'){
    block->setRow(3);
  }
  else{
    block->setRow(4);
  }
  block->setCol(0);
  Coordinates c1 = block->get1stCell();
  Coordinates c2 = block->get2ndCell();
  Coordinates c3 = block->get3rdCell();
  Coordinates c4 = block->get4thCell();
  
  if(theGrid[c1.row][c1.col].canAddBlock(block)
     && theGrid[c2.row][c2.col].canAddBlock(block)
     && theGrid[c3.row][c3.col].canAddBlock(block)
     && theGrid[c4.row][c4.col].canAddBlock(block)){
    theGrid[c1.row][c1.col].setBlock(block);
    theGrid[c2.row][c2.col].setBlock(block);
    theGrid[c3.row][c3.col].setBlock(block);
    theGrid[c4.row][c4.col].setBlock(block);
    blocksSinceClear++;
    return true;
  }
  return false;
}

void Grid::setLevel(int newLevel){
  currentLevel = newLevel;
  td->setLevel(currentLevel);
  if(!textOnly){
    gd->setLevel(currentLevel);
  }
}

void Grid::replaceBlock(std::shared_ptr<AbstractBlock> currBlock,
                        std::shared_ptr<AbstractBlock> newBlock){
  newBlock->setRow(currBlock->getRow());
  newBlock->setCol(currBlock->getCol());
  
  //Get Coords of current Block's cells
  Coordinates currC1 = currBlock->get1stCell();
  Coordinates currC2 = currBlock->get2ndCell();
  Coordinates currC3 = currBlock->get3rdCell();
  Coordinates currC4 = currBlock->get4thCell();
  
  //Clear current block's cells (possibly temporarily);
  theGrid[currC1.row][currC1.col].clearCell();
  theGrid[currC2.row][currC2.col].clearCell();
  theGrid[currC3.row][currC3.col].clearCell();
  theGrid[currC4.row][currC4.col].clearCell();
  
  Coordinates newC1 = newBlock->get1stCell();
  Coordinates newC2 = newBlock->get2ndCell();
  Coordinates newC3 = newBlock->get3rdCell();
  Coordinates newC4 = newBlock->get4thCell();
  
  if(newC1.col < gridWidth && newC2.col < gridWidth
     && newC3.col < gridWidth && newC4.col < gridWidth
     && theGrid[newC1.row][newC1.col].canAddBlock(newBlock)
     && theGrid[newC2.row][newC2.col].canAddBlock(newBlock)
     && theGrid[newC3.row][newC3.col].canAddBlock(newBlock)
     && theGrid[newC4.row][newC4.col].canAddBlock(newBlock)){
    theGrid[newC1.row][newC1.col].setBlock(newBlock);
    theGrid[newC2.row][newC2.col].setBlock(newBlock);
    theGrid[newC3.row][newC3.col].setBlock(newBlock);
    theGrid[newC4.row][newC4.col].setBlock(newBlock);
  }
  else{
    theGrid[currC1.row][currC1.col].setBlock(currBlock);
    theGrid[currC2.row][currC2.col].setBlock(currBlock);
    theGrid[currC3.row][currC3.col].setBlock(currBlock);
    theGrid[currC4.row][currC4.col].setBlock(currBlock);
  }
}
