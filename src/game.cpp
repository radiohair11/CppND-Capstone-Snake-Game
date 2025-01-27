#include "game.h"
#include <iostream>
#include "SDL.h"
#include "map.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      gameMap("map1.txt") {  
    PlaceFood(gameMap);
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  if(gameMap.IsEmpty()) {
    std::cout << "gameMap is empty!\n";
  }

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, gameMap);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood(Map &map) {

  int x, y;
  SDL_Point tryFoodAt;
  bool testFailed = false;

  while (true) {
    testFailed = false;
    x = random_w(engine);
    y = random_h(engine);
    std::cout << "Trying point x: " << x << ", y: " << y << '\n';
    tryFoodAt.x = x;
    tryFoodAt.y = y;
    if (!snake.SnakeCell(x,y)) {
      for ( SDL_Point &wall : map.walls ) {
        if (tryFoodAt.x == wall.x && tryFoodAt.y == wall.y) {
          std::cout << "Tried to place food on wall, choosing another point\n";
          testFailed = true;
        }
      }
    }
    if (!testFailed) {
      food.x = x;
      food.y = y;
      //std::cout << "Food x = " << food.x << ", Food y = " << food.y << '\n';
      return;
    }
  }
}


void Game::Update() {
  if (!snake.alive) return;

  snake.Update(gameMap);

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood(gameMap);
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }