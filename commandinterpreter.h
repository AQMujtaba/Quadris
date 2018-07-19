#ifndef commandInterpreter
#define commandInterpreter

#include <iostream>
#include <string>


class CommandInterpreter {
 public:
  std::string interpretCommand(std::string s, int &multiplier);
};

#endif
