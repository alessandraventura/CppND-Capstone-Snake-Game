#ifndef GAME_H
#define GAME_H

#include <random>

#include "SDL.h"
#include "controller.h"
#include "obstacle.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  SDL_Point food;
  std::vector<Obstacle> obstacles;
  bool increase_speed = false;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  int place_obstacle_counter = 0;

  void PlaceFood();
  void PlaceNewObstacle();
  bool CheckLocationFree(int const &x, int const &y);
  bool IsInObstacleVector(int const &x, int const &y);
  void Update();

  Shape RandomShape();
};

#endif
