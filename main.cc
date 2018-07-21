#include "quadris.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main(int args, char *argv[]) {
  int seed = 1; // default random sequence
  int level = 0; // default starting level
  bool textOnly = false; // default state with no "-text"
  string fileName = "sequence.txt"; // defaut script file

  for (int i = 1; i < args; ++i) {
  	string arg = argv[i];
  	if (arg == "-text") {
  		textOnly = true;
  	} 
  	else if (arg == "-seed") {
  		stringstream in(argv[i + 1]);
  		if (!(in >> seed)) { // check for successful read
  			seed = 1; // back to default if not
  		}
  	} 
  	else if (arg == "-scriptfile") {
  		fileName = argv[i + 1];
  	} 
  	else if (arg == "-startlevel") {
  		stringstream in(argv[i + 1]);
  		if (!(in >> level)) { // check for successful read
  			level = 0; // back to default if not
  		}
  	}
  }

  ifstream file(fileName);
  if ((!(file.good())) && (level == 0)) { // check if file exists/readable
  	cerr << "Please provide a readable file." << endl;
  	return 1;
  }

  Quadris myGame{textOnly, seed, fileName, level};

  try {
  	myGame.Start();
  }
  catch (...) {
  	return 1;
  }
}
