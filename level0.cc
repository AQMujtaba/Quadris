#include "level0.h"
#include "abstractblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "sblock.h"
#include "zblock.h"
#include "oblock.h"
#include "tblock.h"

using namespace std;

Level0::Level0(std::string seqFile): AbstractLevel{false, seqFile}{}

void Level0::setRandom(bool r){
  (void)r;
  random = false;
}

int Level0::getLevel(){
  return 0;
}

shared_ptr<AbstractBlock> Level0::createBlock(){
  if(seqPos != (blockSeq.size()-1)){
    char block = blockSeq[seqPos];
    shared_ptr<AbstractBlock> returnBlock;
    if(block == 'I'){
      returnBlock = make_shared{IBlock}(0,0,0,nullptr);
    }
    else if(block == 'J'){
      returnBlock = make_shared{JBlock}(0,0,0,nullptr);
    }
    else if(block == 'L'){
      returnBlock = make_shared{LBlock}(0,0,0,nullptr);
    }
    else if(block == 'O'){
      returnBlock = make_shared{OBlock}(0,0,0,nullptr);
    }
    else if(block == 'S'){
      returnBlock = make_shared{SBlock}(0,0,0,nullptr);
    }
    else if(block == 'T'){
      returnBlock = make_shared{TBlock}(0,0,0,nullptr);
    }
    else if(block == 'Z'){
      returnBlock = make_shared{ZBlock}(0,0,0,nullptr);
    }
    else{
      
    }
    return returnBlock;
    seqPos++;
  }
  else{
    seqPos = 0;
    return createBlock();
  }
  return nullptr;
}
