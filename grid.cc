#include "grid.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"

Grid::Grid(): td{make_ptr<TextDisplay>()}, gd{make_ptr<GraphicsDisplay>()}{
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

void Grid::left(std::shared_ptr<AbstractBlock> block){
  
}

void Grid::right(std::shared_ptr<AbstractBlock> block){
  
}

void Grid::down(std::shared_ptr<AbstractBlock> block){
  
}

void Grid::drop(std::shared_ptr<AbstractBlock> block){
  
}

void Grid::clockwise(std::shared_ptr<AbstractBlock> block){
  
}

void Grid::counterClockwise(std::shared_ptr<AbstractBlock> block){
  
}

void Grid::newBlock(std::shared_ptr<AbstractBlock> block){
  
}

