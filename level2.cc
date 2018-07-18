#include "level2.h"
#include "abstractblock.h"

using namespace std;

Level2::Level2(std::string seqFile, int seed): AbstractLevel{false, seqFile, seed}{}

void Level2::setRandom(bool r){
  random = r;
}

int Level2::getLevel(){
  return 2;
}

shared_ptr<AbstractBlock> Level2::createBlock(){
  if(random){
    int n = srand(seed) % 7;
    if(n == 0){
      return make_shared{SBlock}();
    }
    else if(n == 1){
      return make_shared{ZBlock}();
    }
    else if(n == 2){
      return make_shared{IBlock}();
    }
    else if(n == 3){
      return make_shared{JBlock}();
    }
    else if(n == 4){
      return make_shared{LBlock}();
    }
    else if(n == 5){
      return make_shared{OBlock}();
    }
    else if(n == 6){
      return make_shared{TBlock}();
    }
    seqPos++;
  }
  else{
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
    }
    else{
      restartSeq();
      return createBlock();
    }
  }
  return nullptr;
}

