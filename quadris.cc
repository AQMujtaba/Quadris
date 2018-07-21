#include "quadris.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

using namespace std;

void Quadris::setLevel(int level){
  if(level <= 0){
    currentLevel = make_shared<Level0>(seqFile, seed);
  }
  else if(level == 1){
    currentLevel = make_shared<Level1>(seqFile, seed);
  }
  else if(level == 2){
    currentLevel = make_shared<Level2>(seqFile, seed);
  }
  else if(level == 3){
    currentLevel = make_shared<Level3>(seqFile, seed);
  }
  else{
    currentLevel = make_shared<Level0>(seqFile, seed);
  }
}

Quadris::Quadris(bool textOnly, int seed, std::string seqFile, int startLevel):
seed{seed}, seqFile{seqFile},
theGrid{nullptr},
myInterpreter{make_unique<CommandInterpreter>()}, scoreKeeper{make_shared<ScoreKeeper>()} {
  setLevel(startLevel);
  theGrid = make_unique<Grid>(textOnly, currentLevel->getLevel(), scoreKeeper);
}

void Quadris::Start(){
  bool gameOver = false;
  currentBlock = currentLevel->createBlock();
  currentBlock->setScoreKeeper(scoreKeeper);
  theGrid->newBlock(currentBlock);
  
  cout << *theGrid;
  
  string aCommand;
  
  while (cin >> aCommand) {
    int multiplier;
    aCommand = myInterpreter->interpretCommand(aCommand, multiplier);
    
    if(gameOver && aCommand != "restart"){
      cerr << "The Game is over. You must enter restart to play again." << endl;
    }
    else if(aCommand == "left"){
      theGrid->left(currentBlock, multiplier);
    }
    else if(aCommand == "right"){
      theGrid->right(currentBlock, multiplier);
    }
    else if(aCommand == "down"){
      theGrid->down(currentBlock, multiplier);
    }
    else if(aCommand == "clockwise"){
      theGrid->clockwise(currentBlock, multiplier);
    }
    else if(aCommand == "counterclockwise"){
      theGrid->counterClockwise(currentBlock, multiplier);
    }
    else if(aCommand == "drop"){
      for(int i = 0; i < multiplier; i++){
        theGrid->drop(currentBlock);
        currentBlock = currentLevel->createBlock();
        currentBlock->setScoreKeeper(scoreKeeper);
        if(!theGrid->newBlock(currentBlock)){
          gameOver = true;
        }
      }
    }
    else if(aCommand == "levelup"){
      int curr = currentLevel->getLevel();
      if (curr + 1 <= 4) { // check if between levels 0 - 4
        setLevel(curr + 1);
        theGrid->setLevel(currentLevel->getLevel());
      }
    }
    else if(aCommand == "leveldown"){
      int curr = currentLevel->getLevel();
      if (curr - 1 >= 0) { // check if between levels 0 - 4
        setLevel(curr - 1);
        theGrid->setLevel(currentLevel->getLevel());
      }
    }
    else if(aCommand == "norandom"){
      string newFile;
      if(cin >> newFile){
        currentLevel->setRandom(false);
        seqFile = newFile;
        currentLevel->setSeqFile(seqFile);
      }
    }
    else if(aCommand == "random"){
      currentLevel->setRandom(true);
    }
    else if(aCommand == "sequence"){
      string newFile;
      if(cin >> newFile){
        seqFile = newFile;
        currentLevel->setSeqFile(seqFile);
      }
    }
    else if(aCommand == "I"){
      shared_ptr<AbstractBlock> newBlock = make_shared<IBlock>(currentLevel->getLevel(),0,0, scoreKeeper);
      currentBlock->togglePlaced(); // deactivate score addition in DTOR
      theGrid->replaceBlock(currentBlock, newBlock);
      currentBlock = newBlock;
    }
    else if(aCommand == "J"){
      shared_ptr<AbstractBlock> newBlock = make_shared<JBlock>(currentLevel->getLevel(),0,0, scoreKeeper);
      currentBlock->togglePlaced(); // deactivate score addition in DTOR
      theGrid->replaceBlock(currentBlock, newBlock);
      currentBlock = newBlock;
    }
    else if(aCommand == "L"){
      shared_ptr<AbstractBlock> newBlock = make_shared<LBlock>(currentLevel->getLevel(),0,0,scoreKeeper);
      currentBlock->togglePlaced(); // deactivate score addition in DTOR
      theGrid->replaceBlock(currentBlock, newBlock);
      currentBlock = newBlock;
    }
    else if(aCommand == "restart"){
      scoreKeeper->resetScore();
      theGrid->reset();
      currentBlock = currentLevel->createBlock();
      currentBlock->setScoreKeeper(scoreKeeper);
      theGrid->newBlock(currentBlock);
    }
    else if(aCommand == "hint"){
      theGrid->hint();
    }
    else if(aCommand == "noCommand"){
      cerr << "INVALID COMMAND" << endl;
    }
    if(gameOver){
      cout << "Game Over. Enter restart to play again" << endl;
    }
    cout << *theGrid;
  }
}
