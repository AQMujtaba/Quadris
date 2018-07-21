#ifndef _scorekeeper_
#define _scorekeeper_

class ScoreKeeper {
  bool hasChanged;
  int score;
  int highScore;
 public:
  ScoreKeeper(int score = 0, int highScore = 0);
  int getScore(bool viewed);
  int getHighScore() const;
  void addScore(int amount);
  void resetScore();
  bool getHasChanged() const;
};

#endif
