#include <game.h>
#include <renderer.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 45
#define HEIGHT 25

int main(void) {
  int frame = 0;
  int content[WIDTH * HEIGHT];
  Game game = {WIDTH, HEIGHT, content};
  init(&game, 0.03);

  while (check_alive(&game)) {
    clear();
    printf("Step: %d\n\n", frame++);
    draw(&game);
    step(&game);
    sleep(1);
  }
  return 0;
}
