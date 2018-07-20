#include scorekeeper.h

ScoreKeeper::ScoreKeeper(score = 0, highScore = 0): score{score}, highScore{highScore}{}

int ScoreKeeper::getScore() const {
  return score;
}

int ScoreKeeper::getHighScore() const {
  return highScore;
}

void ScoreKeeper::addScore(int amount) {
  score += amount;
  if(score > highScore){
    highScore = score;
  }
}

void ScoreKeeper::resetScore() {
  score = 0;
}
