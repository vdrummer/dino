#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "gamestate.h"

#define WIDTH 800
#define HEIGHT 600

void render(SDL_Renderer* r, Gamestate* gs) {
  //TODO TBI
  SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
  SDL_RenderClear(r);

  // render dino
  SDL_Rect rect = {
    .x = gs->dino.x,
    .y = gs->dino.y,
    .w = 50,
    .h = gs->dino.isCrouched ? 50 : 100
  };

  const Color c = gs->dino.color;
  SDL_SetRenderDrawColor(r, c.r, c.g, c.b, 255);
  SDL_RenderFillRect(r, &rect);

  // render obstacles
  for (int i=0; i<gs->numObstacles; i++) {
    rect = (SDL_Rect) {
      .x = gs->obstacles[i].x,
      .y = gs->obstacles[i].y,
      .w = gs->obstacles[i].width,
      .h = gs->obstacles[i].height
    };
   SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
   SDL_RenderFillRect(r, &rect);
  }

  SDL_RenderPresent(r);
}

int main() {
  // SDL init
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

  // gamestate init
  Gamestate state = {0};
  state.dino = (Dino) {
    .x = 20,
    .y = 400,
    .isCrouched = false
  };
  state.obstacles[state.numObstacles] = (Obstacle) {
    .x = 200,
    .y = 450,
    .width = 50,
    .height = 50
  };
  state.numObstacles++;

  // game loop
  bool doRun = true;
  while (doRun) {
    // event handling
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_QUIT:
          doRun = false;
          break;
      }
    }

    // update

    // rendering
    render(r, &state);

  }

  // shutdown
  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
