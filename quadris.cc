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
    currentLevel = make_shared<Level4>(seqFile, seed);
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
  nextBlock = currentLevel->createBlock();
  currentBlock->setScoreKeeper(scoreKeeper);
  nextBlock->setScoreKeeper(scoreKeeper);
  theGrid->newBlock(currentBlock);
  theGrid->updateNextBlock(nextBlock->getShape());
  
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
      if(currentBlock->getLevel() >= 3){
        theGrid->down(currentBlock,1);
      }
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
        currentBlock = nextBlock;
        nextBlock = currentLevel->createBlock();
        currentBlock->setScoreKeeper(scoreKeeper);
        nextBlock->setScoreKeeper(scoreKeeper);
        if(!theGrid->newBlock(currentBlock)){
          gameOver = true;
        }
        else{
          theGrid->updateNextBlock(nextBlock->getShape());
        }
      }
    }
    else if(aCommand == "levelup"){
      for(int i = 0; i < multiplier; i++){
        int curr = currentLevel->getLevel();
        setLevel(curr + 1);
        theGrid->setLevel(currentLevel->getLevel());
      }
    }
    else if(aCommand == "leveldown"){
      for(int i = 0; i < multiplier; i++){
        int curr = currentLevel->getLevel();
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
      gameOver = false;
      setLevel(currentLevel->getLevel());
      scoreKeeper->resetScore();
      theGrid->reset();
      currentBlock->togglePlaced();
      currentBlock = currentLevel->createBlock();
      nextBlock->togglePlaced();
      nextBlock = currentLevel->createBlock();
      currentBlock->setScoreKeeper(scoreKeeper);
      nextBlock->setScoreKeeper(scoreKeeper);
      theGrid->newBlock(currentBlock);
      theGrid->updateNextBlock(nextBlock->getShape());
    }
    else if(aCommand == "hint"){
      theGrid->hint(currentBlock);
    }
    else if(aCommand == "noCommand"){
    }
    cout << *theGrid;
  }
}
