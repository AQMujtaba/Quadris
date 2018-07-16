#include "level1.h"
#include "abstractblock.h"

using namespace std;

Level1::Level1(std::string seqFile): AbstractLevel{false, seqFile, seed}{}

void Level1::setRandom(bool r){
  random = r;
}

int Level1::getLevel(){
  return 1;
}

shared_ptr<AbstractBlock> Level1::createBlock(){
  if(random){
    int n = srand(seed) % 12;
    if(n == 0){
      return make_shared{SBlock}();
    }
    else if(n == 1){
      return make_shared{ZBlock}();
    }
    else if(n == 2 || n == 3){
      return make_shared{IBlock}();
    }
    else if(n == 4 || n == 5){
      return make_shared{JBlock}();
    }
    else if(n == 6 || n == 7){
      return make_shared{LBlock}();
    }
    else if(n == 8 || n == 9){
      return make_shared{OBlock}();
    }
    else if(n == 10 || n == 11){
      return make_shared{TBlock}();
    }
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
