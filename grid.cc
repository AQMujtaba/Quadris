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

Grid::Grid(shared_ptr<AbstractLevel> currentLevel): td{make_ptr<TextDisplay>()}, gd{make_ptr<GraphicsDisplay>()},
currentLevel{currentLevel}{
  for(int rowIndex = 0; rowIndex < gridHeight; rowIndex++){
    vector<Cell> rowVec;
    for(int colIndex = 0; colIndex < gridWidth; colIndex++){
      rowVec.emplace_back(Cell{rowIndex, colIndex});
      rowVec[colIndex].addObserver(td);
      rowVec[colIndex].addObserver(gd);
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
    coordinates c1 = block.get1stCell();
    coordinates c2 = block.get2ndCell();
    coordinates c3 = block.get3rdCell();
    coordinates c4 = block.get4thCell();
    if(c1.col > 0 && c2.col > 0 && c3.col > 0 & c4.col > 0){
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
        block.setCol(block.getCol() - 1);
      }
    }
  }
  if(block.getLevel() >= 3){
    down(block, 1);
  }
}

void Grid::right(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity; i++){
    coordinates c1 = block.get1stCell();
    coordinates c2 = block.get2ndCell();
    coordinates c3 = block.get3rdCell();
    coordinates c4 = block.get4thCell();
    if(c1.col < 10 && c2.col < 10 && c3.col < 10 & c4.col < 10){
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
        block.setCol(block.getCol() + 1);
      }
    }
  }
  if(block.getLevel() >= 3){
    down(block, 1);
  }
}

void Grid::down(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity; i++){
    coordinates c1 = block.get1stCell();
    coordinates c2 = block.get2ndCell();
    coordinates c3 = block.get3rdCell();
    coordinates c4 = block.get4thCell();
    if(c1.row < gridHeight - 1 && c2.row < gridHeight - 1 && c3.row < gridHeight - 1 & c4.row < gridHeight - 1){
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
        block.setRow(block.getRow() + 1);
      }
    }
  }
}

void Grid::drop(std::shared_ptr<AbstractBlock> block){
  int prevRow = 0;
  int newRow = 1;
  while(prevRow < newRow){
    prevRow = block.getRow();
    down(block, 1);
    newRow = block.getRow();
  }
  checkRows();
}

void Grid::clockwise(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity i++){
    coordinates c1 = block.get1stCell();
    coordinates c2 = block.get2ndCell();
    coordinates c3 = block.get3rdCell();
    coordinates c4 = block.get4thCell();
    coordinates newc1 = block.get1stCell(block.getOrientation() + 1);
    coordinates newc2 = block.get2ndCell(block.getOrientation() + 1);
    coordinates newc3 = block.get3rdCell(block.getOrientation() + 1);
    coordinates newc4 = block.get4thCell(block.getOrientation() + 1);
    if(newc1.col < gridWidth && newc2.col < gridWidth && newc3.col < gridWidth & newc4.col < gridWidth){
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
        block.setOrientation(block.getOrientation() + 1);
      }
    }
  }
}

void Grid::counterClockwise(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity i++){
    coordinates c1 = block.get1stCell();
    coordinates c2 = block.get2ndCell();
    coordinates c3 = block.get3rdCell();
    coordinates c4 = block.get4thCell();
    coordinates newc1 = block.get1stCell(block.getOrientation() - 1);
    coordinates newc2 = block.get2ndCell(block.getOrientation() - 1);
    coordinates newc3 = block.get3rdCell(block.getOrientation() - 1);
    coordinates newc4 = block.get4thCell(block.getOrientation() - 1);
    if(newc1.col < gridWidth && newc2.col < gridWidth && newc3.col < gridWidth & newc4.col < gridWidth){
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
        block.setOrientation(block.getOrientation() - 1);
      }
    }
  }
}

void Grid::newBlock(std::shared_ptr<AbstractBlock> block){
  
}

void Grid::setLevel(int newLevel){
  currentLevel = newLevel;
  td->setLevel(currentLevel);
  gd->setLevel(currentLevel);
}

void Grid::replaceBlock(std::shared_ptr<AbstractBlock> currBlock,
                        std::shared_ptr<AbstractBlock> newBlock){
  
}

