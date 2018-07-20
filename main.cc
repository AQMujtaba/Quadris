#include "quadris.h"
#include <string>

using namespace std;

int main(){
  Quadris myGame{false, 1, "sequence.txt", 0};
  myGame.Start();
}
