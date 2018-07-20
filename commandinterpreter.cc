#include "commandinterpreter.h"
#include <vector>

using namespace std;

string CommandInterpreter::interpretCommand(string command, int &multiplier){
  multiplier = 1;
  // If there is a command multiplier at the start store it in multiplier
  // and remove it from the start of command.
  if(command[0] >= '0' && command[0] <= '9'){
    int numberLen = 0;
    while(command[numberLen] >= '0' && command[numberLen] <= '9'){
      numberLen++;
    }
    multiplier = stoi(command.substr(0,numberLen));
    command = command.substr(numberLen, command.length() - numberLen);
  }
  
  vector<string> possibleCommands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", "I", "J", "L", "restart", "hint"};
  
  int i = 0;
  while(i < (int)possibleCommands.size()){
    if(possibleCommands[i].find(command) != 0){
      possibleCommands.erase(possibleCommands.begin()+i);
    }
    else{
      i++;
    }
  }
  if(possibleCommands.size() == 1){
    return possibleCommands[0];
  }
  return "noCommand";
}
