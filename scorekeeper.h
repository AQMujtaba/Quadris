#ifndef _scorekeeper_
#define _scorekeeper_

class Scorekeeper{
  int score;
  int highScore;
 public:
  int getScore() const;
  int getHighScore() const;
  void addScore(int amount);
}

#endif
