#ifndef GAME_H
#define GAME_H
#pragma once

typedef struct {
  const int width;
  const int height;
  int *world;
} Game;

void init(const Game *game, const float chance_of_life);
void step(const Game *);
int check_alive(const Game *);

#endif // !GAME_H
