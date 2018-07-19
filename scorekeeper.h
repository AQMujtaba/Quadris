#ifndef _scorekeeper_
#define _scorekeeper_

class ScoreKeeper{
  int score;
  int highScore;
 public:
  ScoreKeeper(int score = 0, int highScore = 0);
  int getScore() const;
  int getHighScore() const;
  void addScore(int amount);
  void resetScore();
};

#endif
