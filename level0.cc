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

Level0::Level0(std::string seqFile, int seed): AbstractLevel{false, seqFile, seed}{}

void Level0::setRandom(bool r){
  (void)r;
  random = false;
}

int Level0::getLevel(){
  return 0;
}

shared_ptr<AbstractBlock> Level0::createBlock(){
  if(seqPos < (int)(blockSeq.size())){
    char block = blockSeq[seqPos];
    if(block == 'I') {
    return make_shared<IBlock>(0, 0, 0, nullptr);
    }
    else if(block == 'J') {
    return make_shared<JBlock>(0, 0, 0, nullptr);
    }
    else if(block == 'L') {
    return make_shared<LBlock>(0, 0, 0, nullptr);
    }
    else if(block == 'O') {
    return make_shared<OBlock>(0, 0, 0, nullptr);
    }
    else if(block == 'S') {
    return make_shared<SBlock>(0, 0, 0, nullptr);
    }
    else if(block == 'T') {
    return make_shared<TBlock>(0, 0, 0, nullptr);
    }
    else if(block == 'Z') {
    return make_shared<ZBlock>(0, 0, 0, nullptr);
    }
    else{
      
    }
    seqPos++;
  }
  else{
    seqPos = 0;
    return createBlock();
  }
  return nullptr;
}
