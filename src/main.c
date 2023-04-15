#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window* window = SDL_CreateWindow("Dino", 0, 0, WIDTH, HEIGHT, 0);
  if (!window) {
    fprintf(stderr, "Could not init Window: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Renderer* r = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
  if (!r) {
    fprintf(stderr, "Could not init Renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  bool doRun = true;
  while (doRun) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_QUIT:
          doRun = false;
          break;
      }
    }

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderClear(r);

    SDL_RenderPresent(r);
  }

  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
