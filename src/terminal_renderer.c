#include "renderer.h"
#include <stdio.h>

#define ALIVE '@'
#define DEAD ' '

void clear(void) {
  printf("\033[H\033[2J"); // Clear screen + go home (combined)
}

void draw(const Game *game) {
  const long n = game->width * game->height + game->height;
  char c[n + 1];
  c[n] = '\0';

  int pos;

  for (int y = 0; y < game->height; y++) {
    for (int x = 0; x < game->width; x++) {
      pos = y * game->width + x + y;
      if (game->world[pos - y] == 1)
        c[pos] = ALIVE;
      else
        c[pos] = DEAD;
    }
    c[++pos] = '\n';
  }
  printf("%s", c);
}
