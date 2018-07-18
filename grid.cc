#include "grid.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"

using namespace std;

Grid::Grid(shared_ptr<AbstractLevel> currentLevel): td{make_ptr<TextDisplay>()}, gd{make_ptr<GraphicsDisplay>()},
currentLevel{currentLevel}{
  for(int rowIndex = 0; rowIndex < 11; rowIndex++){
    vector<Cell> rowVec;
    for(int colIndex = 0; colIndex < 17; colIndex++){
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
    for(int colIndex = 0; colIndex < 17; colIndex++){
      theGrid[rowIndex][colIndex].clearCell(false);
    }
  }
}

void Grid::left(std::shared_ptr<AbstractBlock> block, int multiplicity){
  for(int i = 0; i < multiplicity; i++){
    
  }
}

void Grid::right(std::shared_ptr<AbstractBlock> block, int multiplicity){
  
}

void Grid::down(std::shared_ptr<AbstractBlock> block, int multiplicity){
  
}

void Grid::drop(std::shared_ptr<AbstractBlock> block){
  
}

void Grid::clockwise(std::shared_ptr<AbstractBlock> block, int multiplicity){
  
}

void Grid::counterClockwise(std::shared_ptr<AbstractBlock> block, int multiplicity){
  
}

void Grid::newBlock(std::shared_ptr<AbstractBlock> block){
  
}

void Grid::setLevel(int newLevel){
  currentLevel = newLevel;
  td->setLevel(currentLevel);
  gd->setLevel(currentLevel);
}

