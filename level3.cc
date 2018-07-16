#include "level3.h"
#include "abstractblock.h"

using namespace std;

Level3::Level3(std::string seqFile): AbstractLevel{false, seqFile, seed}{}

void Level3::setRandom(bool r){
  random = r;
}

int Level3::getLevel(){
  return 3;
}

shared_ptr<AbstractBlock> Level3::createBlock(){
  if(random){
    int n = srand(seed) % 9;
    if(n == 0 || n == 1){
      return make_shared{SBlock}();
    }
    else if(n == 2 || n == 3){
      return make_shared{ZBlock}();
    }
    else if(n == 4){
      return make_shared{IBlock}();
    }
    else if(n == 5){
      return make_shared{JBlock}();
    }
    else if(n == 6){
      return make_shared{LBlock}();
    }
    else if(n == 7){
      return make_shared{OBlock}();
    }
    else if(n == 8){
      return make_shared{TBlock}();
    }
    seqPos++
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

