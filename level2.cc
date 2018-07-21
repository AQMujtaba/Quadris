#include "level2.h"
#include "abstractblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "sblock.h"
#include "zblock.h"
#include "oblock.h"
#include "tblock.h"

using namespace std;

Level2::Level2(std::string seqFile, int seed): AbstractLevel{true, seqFile, seed}{}

void Level2::setRandom(bool r){
  random = r;
}

int Level2::getLevel(){
  return 2;
}

shared_ptr<AbstractBlock> Level2::createBlock(){
  if(random){

  srand(seed);
  int n = rand() % 7;
    
  if(n == 0){
      return make_shared<SBlock>(2, 0, 0, nullptr);
    }
    else if(n == 1 ){
      return make_shared<ZBlock>(2, 0, 0, nullptr);
    }
    else if(n == 2) {
      return make_shared<IBlock>(2, 0, 0, nullptr);
    }
    else if(n == 3) {
      return make_shared<JBlock>(2, 0, 0, nullptr);
    }
    else if(n == 4) {
      return make_shared<LBlock>(2, 0, 0, nullptr);
    }
    else if(n == 5) {
      return make_shared<OBlock>(2, 0, 0, nullptr);
    }
    else if(n == 6) {
      return make_shared<TBlock>(2, 0, 0, nullptr);
    }
    seqPos++;
  }
  else{
    if(seqPos != (int)(blockSeq.size()-1)){
      char block = blockSeq[seqPos];
      if(block == 'I') {
        return make_shared<IBlock>(2, 0, 0, nullptr);
      }
      else if(block == 'J') {
        return make_shared<JBlock>(2, 0, 0, nullptr);
      }
      else if(block == 'L') {
        return make_shared<LBlock>(2, 0, 0, nullptr);
      }
      else if(block == 'O') {
        return make_shared<OBlock>(2, 0, 0, nullptr);
      }
      else if(block == 'S') {
        return make_shared<SBlock>(2, 0, 0, nullptr);
      }
      else if(block == 'T') {
        return make_shared<TBlock>(2, 0, 0, nullptr);
      }
      else if(block == 'Z') {
        return make_shared<ZBlock>(2, 0, 0, nullptr);
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

