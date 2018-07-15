#ifndef _quadris_
#define _quadris_

#include <iostream>
#include <memory.h>
#include "commandinterpreter.h"

class Quadris {
  
  std::unique_ptr<CommandInterpreter> commandInterpreter;
 public:
  void start();
};

#endif
