#include "grid.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "singleblock.h"

using namespace std;

void Grid::checkRows(){
  int clearCount = 0;
  for(int rowIndex = gridHeight-1; rowIndex >= 0; rowIndex--){
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
  if(clearCount != 0){
    blocksSinceClear = 0;
    int scoreToAdd = currentLevel + clearCount;
    scoreToAdd *= scoreToAdd;
    scoreKeeper->addScore(scoreToAdd);
  }
}

void Grid::clearRow(int row){
  for(int colIndex = 0; colIndex < gridWidth; colIndex++){
    theGrid[row][colIndex].clearCell(true);
  }
}

void Grid::shiftRowsDown(int startRow){
  if(startRow > 0){
    for(int colIndex = 0; colIndex < gridWidth; colIndex++){
      shared_ptr<AbstractBlock> newBlock = theGrid[startRow-1][colIndex].getBlock();
      if(newBlock != nullptr){
        theGrid[startRow][colIndex].setBlock(newBlock);
        theGrid[startRow-1][colIndex].clearCell(true);
      }
    }
    shiftRowsDown(startRow - 1);
  }
}

void Grid::clearHintBlock(){
  Coordinates c1 = hintBlock->get1stCell();
  Coordinates c2 = hintBlock->get2ndCell();
  Coordinates c3 = hintBlock->get3rdCell();
  Coordinates c4 = hintBlock->get4thCell();
  theGrid[c1.row][c1.col].clearCell(false);
  theGrid[c2.row][c2.col].clearCell(false);
  theGrid[c3.row][c3.col].clearCell(false);
  theGrid[c4.row][c4.col].clearCell(false);
  hintBlock = nullptr;
}


void Grid::dropSingleBlock(){
  shared_ptr<SingleBlock> newBlock;
  newBlock = make_shared<SingleBlock>(0,0,0, scoreKeeper);
  newBlock->togglePlaced();
  int rowIndex = gridHeight-1;
  while(rowIndex >= 0 && !theGrid[rowIndex][5].canAddBlock(newBlock)){
    rowIndex--;
  }
  theGrid[rowIndex][5].setBlock(newBlock);
}

Grid::Grid(bool textOnly, int currentLevel, std::shared_ptr<ScoreKeeper> scoreKeeper): textOnly{textOnly}, currentLevel{currentLevel}, blocksSinceClear{0}, td{make_shared<TextDisplay>(currentLevel, scoreKeeper)}, gd{textOnly ? nullptr : make_shared<GraphicsDisplay>(currentLevel, scoreKeeper)}, scoreKeeper{scoreKeeper}{
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

void Grid::hint(std::shared_ptr<AbstractBlock> block) {
  if (hintBlock) { // clear previous block if it exists
    clearHintBlock();
  }
  // create a copy of the block, with "hint settings" activated
  shared_ptr<AbstractBlock> hintBlock = block->createHint();
  int currRow = block->getRow();
  int currCol = block->getCol();
  int height = 0; // starting height on grid

  Coordinates ogC1 = block->get1stCell(); // get coordinates of og block
  Coordinates ogC2 = block->get2ndCell();
  Coordinates ogC3 = block->get3rdCell();
  Coordinates ogC4 = block->get4thCell();

  theGrid[ogC1.row][ogC1.col].clearCell(false); // clear cells of og block
  theGrid[ogC2.row][ogC2.col].clearCell(false);
  theGrid[ogC3.row][ogC3.col].clearCell(false);
  theGrid[ogC4.row][ogC4.col].clearCell(false);

  for (int orientation = 0; orientation <= 3; ++orientation) {
    shared_ptr<AbstractBlock> tempHintBlock = block->createHint();
    // adjust orientations
    tempHintBlock->setOrientation(tempHintBlock->getOrientation() + orientation);

    // get temp's coordinates
    Coordinates c1 = tempHintBlock->get1stCell();
    Coordinates c2 = tempHintBlock->get2ndCell();
    Coordinates c3 = tempHintBlock->get3rdCell();
    Coordinates c4 = tempHintBlock->get4thCell();

    // if orientation is valid:
    if(c1.col < gridWidth && c2.col < gridWidth 
       && c3.col < gridWidth && c4.col < gridWidth){
      if(theGrid[c1.row][c1.col].canAddBlock(tempHintBlock)
         && theGrid[c2.row][c2.col].canAddBlock(tempHintBlock)
         && theGrid[c3.row][c3.col].canAddBlock(tempHintBlock)
         && theGrid[c4.row][c4.col].canAddBlock(tempHintBlock)){

        while(c1.col > 0 && c2.col > 0 // how far left without obstruction
            && c3.col > 0 && c4.col > 0
            && theGrid[c1.row][c1.col - 1].canAddBlock(tempHintBlock)
            && theGrid[c2.row][c2.col - 1].canAddBlock(tempHintBlock)
            && theGrid[c3.row][c3.col - 1].canAddBlock(tempHintBlock)
            && theGrid[c4.row][c4.col - 1].canAddBlock(tempHintBlock)) {

          tempHintBlock->setCol(tempHintBlock->getCol() - 1);          

          // how far down on left side
          while(c1.row < gridHeight - 1 && c2.row < gridHeight - 1
              && c3.row < gridHeight - 1 && c4.row < gridHeight - 1
              && theGrid[c1.row + 1][c1.col].canAddBlock(tempHintBlock)
              && theGrid[c2.row + 1][c2.col].canAddBlock(tempHintBlock)
              && theGrid[c3.row + 1][c3.col].canAddBlock(tempHintBlock)
              && theGrid[c4.row + 1][c4.col].canAddBlock(tempHintBlock)){
            tempHintBlock->setRow(tempHintBlock->getRow() + 1);
            c1 = tempHintBlock->get1stCell();
            c2 = tempHintBlock->get2ndCell();
            c3 = tempHintBlock->get3rdCell();
            c4 = tempHintBlock->get4thCell();
          }

          //check how low it went
          int tempHeight = tempHintBlock->getRow() - tempHintBlock->getHeight();
          // save changes if needed
          if (height < tempHeight) {
            height = tempHeight;
            hintBlock->setCol(tempHintBlock->getCol());
            hintBlock->setRow(tempHintBlock->getRow());
            hintBlock->setOrientation(tempHintBlock->getOrientation());
          }

          tempHintBlock->setRow(currRow);
          c1 = tempHintBlock->get1stCell();
          c2 = tempHintBlock->get2ndCell();
          c3 = tempHintBlock->get3rdCell();
          c4 = tempHintBlock->get4thCell();
        }

        tempHintBlock->setCol(currCol); // reset 
        tempHintBlock->setRow(currRow); // starting point

        while(c1.col < 10 && c2.col < 10 // how far right without obstruction
            && c3.col < 10 && c4.col < 10
            && theGrid[c1.row][c1.col + 1].canAddBlock(tempHintBlock)
            && theGrid[c2.row][c2.col + 1].canAddBlock(tempHintBlock)
            && theGrid[c3.row][c3.col + 1].canAddBlock(tempHintBlock)
            && theGrid[c4.row][c4.col + 1].canAddBlock(tempHintBlock)) {

          tempHintBlock->setCol(tempHintBlock->getCol() + 1);          

          // how far down on right side
          while(c1.row < gridHeight - 1 && c2.row < gridHeight - 1
              && c3.row < gridHeight - 1 && c4.row < gridHeight - 1
              && theGrid[c1.row + 1][c1.col].canAddBlock(tempHintBlock)
              && theGrid[c2.row + 1][c2.col].canAddBlock(tempHintBlock)
              && theGrid[c3.row + 1][c3.col].canAddBlock(tempHintBlock)
              && theGrid[c4.row + 1][c4.col].canAddBlock(tempHintBlock)){
            tempHintBlock->setRow(tempHintBlock->getRow() + 1);
            c1 = tempHintBlock->get1stCell();
            c2 = tempHintBlock->get2ndCell();
            c3 = tempHintBlock->get3rdCell();
            c4 = tempHintBlock->get4thCell();
          }

          //check how low it went
          int tempHeight = tempHintBlock->getRow() - tempHintBlock->getHeight();
          // save changes if needed
          if (height < tempHeight) {
            height = tempHeight;
            hintBlock->setCol(tempHintBlock->getCol());
            hintBlock->setRow(tempHintBlock->getRow());
            hintBlock->setOrientation(tempHintBlock->getOrientation());
          }

          tempHintBlock->setRow(currRow);
          c1 = tempHintBlock->get1stCell();
          c2 = tempHintBlock->get2ndCell();
          c3 = tempHintBlock->get3rdCell();
          c4 = tempHintBlock->get4thCell();
        }
      }
    }
  }

  this->hintBlock = hintBlock; // set grid hintBlock to best hintBlock

  theGrid[ogC1.row][ogC1.col].setBlock(block); // place ogBlock back on grid
  theGrid[ogC2.row][ogC2.col].setBlock(block);
  theGrid[ogC3.row][ogC3.col].setBlock(block);
  theGrid[ogC4.row][ogC4.col].setBlock(block);   

  Coordinates c1 = hintBlock->get1stCell(); // get hintBlock's coordinates
  Coordinates c2 = hintBlock->get2ndCell();
  Coordinates c3 = hintBlock->get3rdCell();
  Coordinates c4 = hintBlock->get4thCell();

  theGrid[c1.row][c1.col].setBlock(hintBlock); // place hintBlock on grid
  theGrid[c2.row][c2.col].setBlock(hintBlock);
  theGrid[c3.row][c3.col].setBlock(hintBlock);
  theGrid[c4.row][c4.col].setBlock(hintBlock);  
}

void Grid::reset(){
  for(int rowIndex = 0; rowIndex < gridHeight; rowIndex++){
    for(int colIndex = 0; colIndex < gridWidth; colIndex++){
      theGrid[rowIndex][colIndex].clearCell(false);
    }
  }
}

void Grid::updateNextBlock(char type){
  td->updateNextBlock(type);
  gd->updateNextBlock(type);
}

void Grid::left(std::shared_ptr<AbstractBlock> block, int multiplicity){
  if (hintBlock) {
    clearHintBlock();
  }
  Coordinates c1 = block->get1stCell();
  Coordinates c2 = block->get2ndCell();
  Coordinates c3 = block->get3rdCell();
  Coordinates c4 = block->get4thCell();
  theGrid[c1.row][c1.col].clearCell(true);
  theGrid[c2.row][c2.col].clearCell(true);
  theGrid[c3.row][c3.col].clearCell(true);
  theGrid[c4.row][c4.col].clearCell(true);
  int i = 0;
  while(i < multiplicity && c1.col > 0 && c2.col > 0
        && c3.col > 0 && c4.col > 0
        && theGrid[c1.row][c1.col - 1].canAddBlock(block)
        && theGrid[c2.row][c2.col - 1].canAddBlock(block)
        && theGrid[c3.row][c3.col - 1].canAddBlock(block)
        && theGrid[c4.row][c4.col - 1].canAddBlock(block)){
    block->setCol(block->getCol() - 1);
    c1 = block->get1stCell();
    c2 = block->get2ndCell();
    c3 = block->get3rdCell();
    c4 = block->get4thCell();
    i++;
  }
  theGrid[c1.row][c1.col].setBlock(block);
  theGrid[c2.row][c2.col].setBlock(block);
  theGrid[c3.row][c3.col].setBlock(block);
  theGrid[c4.row][c4.col].setBlock(block);
  
  if(block->getLevel() >= 3){
    down(block, 1);
  }
}

void Grid::right(std::shared_ptr<AbstractBlock> block, int multiplicity){
  if (hintBlock) {
    clearHintBlock();
  }
  Coordinates c1 = block->get1stCell();
  Coordinates c2 = block->get2ndCell();
  Coordinates c3 = block->get3rdCell();
  Coordinates c4 = block->get4thCell();
  theGrid[c1.row][c1.col].clearCell(true);
  theGrid[c2.row][c2.col].clearCell(true);
  theGrid[c3.row][c3.col].clearCell(true);
  theGrid[c4.row][c4.col].clearCell(true);
  int i = 0;
  while(i < multiplicity && c1.col < 10 && c2.col < 10
        && c3.col < 10 && c4.col < 10
        && theGrid[c1.row][c1.col + 1].canAddBlock(block)
        && theGrid[c2.row][c2.col + 1].canAddBlock(block)
        && theGrid[c3.row][c3.col + 1].canAddBlock(block)
        && theGrid[c4.row][c4.col + 1].canAddBlock(block)){
    block->setCol(block->getCol() + 1);
    c1 = block->get1stCell();
    c2 = block->get2ndCell();
    c3 = block->get3rdCell();
    c4 = block->get4thCell();
    i++;
  }
  theGrid[c1.row][c1.col].setBlock(block);
  theGrid[c2.row][c2.col].setBlock(block);
  theGrid[c3.row][c3.col].setBlock(block);
  theGrid[c4.row][c4.col].setBlock(block);
  
  if(block->getLevel() >= 3){
    down(block, 1);
  }
}

void Grid::down(std::shared_ptr<AbstractBlock> block, int multiplicity){
  if (hintBlock) {
    clearHintBlock();
  }
  Coordinates c1 = block->get1stCell();
  Coordinates c2 = block->get2ndCell();
  Coordinates c3 = block->get3rdCell();
  Coordinates c4 = block->get4thCell();
  theGrid[c1.row][c1.col].clearCell(true);
  theGrid[c2.row][c2.col].clearCell(true);
  theGrid[c3.row][c3.col].clearCell(true);
  theGrid[c4.row][c4.col].clearCell(true);
  int i = 0;
  while(i < multiplicity && c1.row < gridHeight - 1 && c2.row < gridHeight - 1
        && c3.row < gridHeight - 1 && c4.row < gridHeight - 1
        &&theGrid[c1.row + 1][c1.col].canAddBlock(block)
        && theGrid[c2.row + 1][c2.col].canAddBlock(block)
        && theGrid[c3.row + 1][c3.col].canAddBlock(block)
        && theGrid[c4.row + 1][c4.col].canAddBlock(block)){
    block->setRow(block->getRow() + 1);
    c1 = block->get1stCell();
    c2 = block->get2ndCell();
    c3 = block->get3rdCell();
    c4 = block->get4thCell();
    i++;
  }
  theGrid[c1.row][c1.col].setBlock(block);
  theGrid[c2.row][c2.col].setBlock(block);
  theGrid[c3.row][c3.col].setBlock(block);
  theGrid[c4.row ][c4.col].setBlock(block);
}

void Grid::drop(std::shared_ptr<AbstractBlock> block){
  if (hintBlock) {
    clearHintBlock();
  }
  Coordinates c1 = block->get1stCell();
  Coordinates c2 = block->get2ndCell();
  Coordinates c3 = block->get3rdCell();
  Coordinates c4 = block->get4thCell();
  theGrid[c1.row][c1.col].clearCell(true);
  theGrid[c2.row][c2.col].clearCell(true);
  theGrid[c3.row][c3.col].clearCell(true);
  theGrid[c4.row][c4.col].clearCell(true);
  while(c1.row < gridHeight - 1 && c2.row < gridHeight - 1
        && c3.row < gridHeight - 1 && c4.row < gridHeight - 1
        && theGrid[c1.row + 1][c1.col].canAddBlock(block)
        && theGrid[c2.row + 1][c2.col].canAddBlock(block)
        && theGrid[c3.row + 1][c3.col].canAddBlock(block)
        && theGrid[c4.row + 1][c4.col].canAddBlock(block)){
    block->setRow(block->getRow() + 1);
    c1 = block->get1stCell();
    c2 = block->get2ndCell();
    c3 = block->get3rdCell();
    c4 = block->get4thCell();
  }
  theGrid[c1.row][c1.col].setBlock(block);
  theGrid[c2.row][c2.col].setBlock(block);
  theGrid[c3.row][c3.col].setBlock(block);
  theGrid[c4.row][c4.col].setBlock(block);
  checkRows();
}

void Grid::clockwise(std::shared_ptr<AbstractBlock> block, int multiplicity){
  if (hintBlock) {
    clearHintBlock();
  }
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
        theGrid[c1.row][c1.col].clearCell(true);
        theGrid[c2.row][c2.col].clearCell(true);
        theGrid[c3.row][c3.col].clearCell(true);
        theGrid[c4.row][c4.col].clearCell(true);
        theGrid[newc1.row][newc1.col].setBlock(block);
        theGrid[newc2.row][newc2.col].setBlock(block);
        theGrid[newc3.row][newc3.col].setBlock(block);
        theGrid[newc4.row][newc4.col].setBlock(block);
        block->setOrientation(block->getOrientation() + 1);
      }
    }
  }
  if(block->getLevel() >= 3){
    down(block, 1);
  }
}

void Grid::counterClockwise(std::shared_ptr<AbstractBlock> block, int multiplicity){
  if (hintBlock) {
    clearHintBlock();
  }
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
        theGrid[c1.row][c1.col].clearCell(true);
        theGrid[c2.row][c2.col].clearCell(true);
        theGrid[c3.row][c3.col].clearCell(true);
        theGrid[c4.row][c4.col].clearCell(true);
        theGrid[newc1.row][newc1.col].setBlock(block);
        theGrid[newc2.row][newc2.col].setBlock(block);
        theGrid[newc3.row][newc3.col].setBlock(block);
        theGrid[newc4.row][newc4.col].setBlock(block);
        block->setOrientation(block->getOrientation() - 1);
      }
    }
  }
  if(block->getLevel() >= 3){
    down(block, 1);
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
    
    if(block->getLevel() == 4){
      blocksSinceClear++;
    }
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
  if (hintBlock) { // clear hint block if it exists
    clearHintBlock();
  }

  newBlock->setRow(currBlock->getRow());
  newBlock->setCol(currBlock->getCol());
  
  //Get Coords of current Block's cells
  Coordinates currC1 = currBlock->get1stCell();
  Coordinates currC2 = currBlock->get2ndCell();
  Coordinates currC3 = currBlock->get3rdCell();
  Coordinates currC4 = currBlock->get4thCell();
  
  //Clear current block's cells (possibly temporarily);
  theGrid[currC1.row][currC1.col].clearCell(true);
  theGrid[currC2.row][currC2.col].clearCell(true);
  theGrid[currC3.row][currC3.col].clearCell(true);
  theGrid[currC4.row][currC4.col].clearCell(true);
  
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

ostream &operator<<(ostream &out, const Grid &grid){
  out << *(grid.td);
  return out;
}
