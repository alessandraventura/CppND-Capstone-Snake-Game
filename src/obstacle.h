#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <vector>

#include "SDL.h"

enum class Shape { L, T, I };

class Obstacle {
 public:
  Obstacle(Shape s, SDL_Point center) : shape(s), center_position(center) {
    MakeObstacle();
  }
  ~Obstacle(){};

  std::vector<SDL_Point> GetObstaclePoints() const { return obstacle; }

 protected:
  void MakeObstacle();

 private:
  std::vector<SDL_Point> MakeL();
  std::vector<SDL_Point> MakeT();
  std::vector<SDL_Point> MakeI();

  SDL_Point center_position;
  std::vector<SDL_Point> obstacle;

  Shape shape;
};

#endif