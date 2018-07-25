#include "level4.h"
#include "abstractblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "sblock.h"
#include "zblock.h"
#include "oblock.h"
#include "tblock.h"

using namespace std;

Level4::Level4(std::string seqFile, int seed): AbstractLevel{true, seqFile, seed}{
  srand(seed);
}

void Level4::setRandom(bool r){
  random = r;
}

int Level4::getLevel() const{
  return 4;
}

shared_ptr<AbstractBlock> Level4::createBlock(){
  if(random){

    int n = rand() % 9; 

    if(n == 0 || n == 1) {
      return make_shared<SBlock>(4, 0, 0, nullptr);
    }
    else if(n == 2 || n == 3) {
      return make_shared<ZBlock>(4, 0, 0, nullptr);
    }
    else if(n == 4) {
      return make_shared<IBlock>(4, 0, 0, nullptr);
    }
    else if(n == 5) {
      return make_shared<JBlock>(4, 0, 0, nullptr);
    }
    else if(n == 6) {
      return make_shared<LBlock>(4, 0, 0, nullptr);
    }
    else if(n == 7) {
      return make_shared<OBlock>(4, 0, 0, nullptr);
    }
    else if(n == 8) {
      return make_shared<TBlock>(4, 0, 0, nullptr);
    }
  }
  else{
    if(seqPos < (int)(blockSeq.size())) {
      char block = blockSeq[seqPos];
      seqPos++;
      if(block == 'I') {
        return make_shared<IBlock>(4, 0, 0, nullptr);
      }
      else if(block == 'J') {
        return make_shared<JBlock>(4, 0, 0, nullptr);
      }
      else if(block == 'L') {
        return make_shared<LBlock>(4, 0, 0, nullptr);
      }
      else if(block == 'O') {
        return make_shared<OBlock>(4, 0, 0, nullptr);
      }
      else if(block == 'S') {
        return make_shared<SBlock>(4, 0, 0, nullptr);
      }
      else if(block == 'T') {
        return make_shared<TBlock>(4, 0, 0, nullptr);
      }
      else if(block == 'Z') {
        return make_shared<ZBlock>(4, 0, 0, nullptr);
      }
      else{
        // ****** missing something?
      }
    }
    else{
      seqPos = 0;
      return createBlock();
    }
  }
  return nullptr;
}
