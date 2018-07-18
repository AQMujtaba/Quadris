#ifndef _scorekeeper_
#define _scorekeeper_

class ScoreKeeper{
  int score;
  int highScore;
 public:
  ScoreKeeper(score = 0, highScore = 0);
  int getScore() const;
  int getHighScore() const;
  void addScore(int amount);
}

#endif
