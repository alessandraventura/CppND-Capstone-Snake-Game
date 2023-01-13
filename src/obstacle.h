#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <vector>

#include "SDL.h"

enum class Shape { L, T, I };

class Obstacle {
 public:
  Obstacle(Shape s, SDL_Point center) : shape(s), center_position(center){};
  ~Obstacle(){};

  std::vector<SDL_Point> MakeObstacle();

 protected:
 private:
  std::vector<SDL_Point> MakeL();
  std::vector<SDL_Point> MakeT();
  std::vector<SDL_Point> MakeI();

  SDL_Point center_position;
  Shape shape;
};

#endif