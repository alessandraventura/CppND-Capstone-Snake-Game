#include "game.h"

#include <iostream>
#include <random>
#include <vector>

#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    if (!snake.alive) {
      return;
    }
    renderer.Render(snake, food, obstacles);

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

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

bool Game::IsInObstacleVector(int const &x, int const &y) {
  for (auto &i : obstacles) {
    std::vector<SDL_Point> points = i.GetObstaclePoints();
    for (auto &j : points) {
      if (j.x == x && j.y == y) {
        return true;
      }
    }
  }
  return false;
}

bool Game::CheckLocationFree(int const &x, int const &y) {
  if (!snake.SnakeCell(x, y) && (food.x != x) && (food.y != y) &&
      !IsInObstacleVector(x, y)) {
    return true;
  }
  return false;
}

Shape Game::RandomShape() {
  std::random_device random_shape;
  std::uniform_int_distribution<int> dist(1, 3);
  int shape = dist(random_shape);
  switch (shape) {
    case 1:
      return Shape::I;
    case 2:
      return Shape::L;
    case 3:
      return Shape::T;
  }
  return Shape::T;
}

void Game::PlaceNewObstacle() {
  int x, y;
  SDL_Point new_obstacle;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location and adjacent locations are free before placing
    // a new obstacle.
    if (CheckLocationFree(x, y) && CheckLocationFree(x + 1, y) &&
        CheckLocationFree(x - 1, y) && CheckLocationFree(x, y + 1) &&
        CheckLocationFree(x, y - 1)) {
      new_obstacle.x = x;
      new_obstacle.y = y;
      obstacles.emplace_back(Obstacle(RandomShape(), new_obstacle));
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) {
    std::cout << "Game Over" << std::endl;
    return;
  }

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's an obstacle over here
  if (IsInObstacleVector(new_x, new_y)) {
    std::cout << "Game Over" << std::endl;
    snake.alive = false;

    return;
  } else {
    if ((snake.body.size() % 3 == 0) && (snake.body.size() > 1) &&
        place_obstacle_counter == 3) {
      PlaceNewObstacle();
      place_obstacle_counter = 0;
    }
  }

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    place_obstacle_counter++;
    PlaceFood();
    // Grow snake and increase speed every other time we eat.
    snake.GrowBody();
    if (increase_speed) {
      snake.speed += 0.01;
      increase_speed = false;
    } else {
      increase_speed = true;
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }