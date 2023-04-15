#ifndef DINO_GAMESTATE_H
#define DINO_GAMESTATE_H

#include <stdbool.h>

#define MAX_OBSTACLES 1

struct color {
  int r;
  int g;
  int b;
};
typedef struct color Color;

struct dino {
  int x;
  int y;
  bool isCrouched;
  Color color;
};
typedef struct dino Dino;

struct obstacle {
  int x;
  int y;
  int width;
  int height;
};
typedef struct obstacle Obstacle;

struct gamestate {
  Dino dino;
  Obstacle obstacles[MAX_OBSTACLES];
  int numObstacles;
  int score;
  double speed;
  bool isGameOver;
};
typedef struct gamestate Gamestate;

#endif // DINO_GAMESTATE_H
