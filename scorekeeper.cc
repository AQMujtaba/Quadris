#include "scorekeeper.h"

ScoreKeeper::ScoreKeeper(int score, int highScore): score{score}, highScore{highScore}{}

int ScoreKeeper::getScore(bool viewed) {
  if(viewed){
    hasChanged = false;
  }
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
  hasChanged = true;
}

void ScoreKeeper::resetScore() {
  score = 0;
  hasChanged = true;
}

bool ScoreKeeper::getHasChanged() const{
  return hasChanged;
}
