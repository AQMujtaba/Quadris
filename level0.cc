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
  random = false;
}

int Level0::getLevel(){
  return 0;
}

shared_ptr<AbstractBlock> Level0::createBlock(){
  if(seqPos != (blockSeq.size()-1)){
    char block = blockSeq[seqPos];
    if(block == 'I'){
      return make_shared{IBlock}();
    }
    else if(block == 'J'){
      return make_shared{JBlock}();
    }
    else if(block == 'L'){
      return make_shared{LBlock}();
    }
    else if(block == 'O'){
      return make_shared{OBlock}();
    }
    else if(block == 'S'){
      return make_shared{SBlock}();
    }
    else if(block == 'T'){
      return make_shared{TBlock}();
    }
    else if(block == 'Z'){
      return make_shared{ZBlock}();
    }
    else{
      
    }
    seqPos++;
  }
  else{
    restartSeq();
    return createBlock();
  }
  return nullptr;
}
