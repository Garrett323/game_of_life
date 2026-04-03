#include <game.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float probe(void) { return (float)(rand() % 100) / 100; }

void init(const Game *game, const float chance_of_life) {
  srand(time(NULL));
  int size = game->width * game->height;
  for (int i = 0; i < size; i++) {
    if (probe() < chance_of_life)
      game->world[i] = 1;
    else
      game->world[i] = 0;
  }
}

int get(const Game *game, int x, int y) {
  if (x < 0 || x >= game->width || y < 0 || y >= game->height)
    return 0;
  return game->world[y * game->width + x];
}

int get_n_neighbors(const Game *game, const int x, const int y) {
  return get(game, x - 1, y - 1) + get(game, x, y - 1) +
         get(game, x + 1, y - 1) + get(game, x - 1, y) + get(game, x + 1, y) +
         get(game, x - 1, y + 1) + get(game, x, y + 1) +
         get(game, x + 1, y + 1);
}

void step(const Game *game) {
  int pos, n_neighbor;
  int n = game->width * game->height;
  int current_state[n];
  memcpy(current_state, game->world, sizeof(int) * n);
  Game old = {game->width, game->height, current_state};

  for (int y = 0; y < game->height; y++) {
    for (int x = 0; x < game->width; x++) {
      pos = y * game->width + x;
      n_neighbor = get_n_neighbors(&old, x, y);
      if (game->world[pos] == 1)
        game->world[pos] = (n_neighbor == 3) || (n_neighbor == 2) ? 1 : 0;
      else
        game->world[pos] = n_neighbor == 3 ? 1 : 0;
    }
  }
}

int check_alive(const Game *game) {
  int n = game->width * game->height;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += game->world[i];
  }
  return sum;
}
