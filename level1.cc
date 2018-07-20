#include "level1.h"
#include "abstractblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "sblock.h"
#include "zblock.h"
#include "oblock.h"
#include "tblock.h"

using namespace std;

Level1::Level1(std::string seqFile, int seed): AbstractLevel{false, seqFile, seed}{}

void Level1::setRandom(bool r){
  random = r;
}

int Level1::getLevel(){
  return 1;
}

shared_ptr<AbstractBlock> Level1::createBlock(){
  if(random){

  srand(seed);
    int n = rand() % 12;

    if(n == 0){
      return make_shared<SBlock>(1, 0, 0, nullptr);
    }
    else if(n == 1){
      return make_shared<ZBlock>(1, 0, 0, nullptr);
    }
    else if(n == 2 || n == 3){
      return make_shared<IBlock>(1, 0, 0, nullptr);
    }
    else if(n == 4 || n == 5){
      return make_shared<JBlock>(1, 0, 0, nullptr);
    }
    else if(n == 6 || n == 7){
      return make_shared<LBlock>(1, 0, 0, nullptr);
    }
    else if(n == 8 || n == 9){
      return make_shared<OBlock>(1, 0, 0, nullptr);
    }
    else if(n == 10 || n == 11){
      return make_shared<TBlock>(1, 0, 0, nullptr);
    }
    seqPos++;
  }
  else{
    if(seqPos != (int)(blockSeq.size()-1)){
      char block = blockSeq[seqPos];
      if(block == 'I'){
        return make_shared<IBlock>(1, 0, 0, nullptr);
      }
      else if(block == 'J'){
        return make_shared<JBlock>(1, 0, 0, nullptr);
      }
      else if(block == 'L'){
        return make_shared<LBlock>(1,0 , 0, nullptr);
      }
      else if(block == 'O'){
        return make_shared<OBlock>(1, 0, 0, nullptr);
      }
      else if(block == 'S'){
        return make_shared<SBlock>(1, 0, 0, nullptr);
      }
      else if(block == 'T'){
        return make_shared<TBlock>(1, 0, 0, nullptr);
      }
      else if(block == 'Z'){
        return make_shared<ZBlock>(1, 0, 0, nullptr);
      }
      else{
        
      }
    }
    else{
      seqPos = 0;
      return createBlock();
    }
  }
  return nullptr;
}
