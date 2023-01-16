#include "obstacle.h"

void Obstacle::MakeObstacle() {
  switch (shape) {
    case Shape::L:
      obstacle = MakeL();
      break;
    case Shape::T:
      obstacle = MakeT();
      break;
    case Shape::I:
      obstacle = MakeI();
      break;
  }
}

std::vector<SDL_Point> Obstacle::MakeL() {
  std::vector<SDL_Point> L;
  SDL_Point top;
  SDL_Point right;

  top.x = center_position.x;
  top.y = center_position.y - 1;
  right.x = center_position.x + 1;
  right.y = center_position.y;

  L.emplace_back(center_position);
  L.emplace_back(top);
  L.emplace_back(right);

  return L;
}

std::vector<SDL_Point> Obstacle::MakeT() {
  std::vector<SDL_Point> T;
  SDL_Point bottom;
  SDL_Point right;
  SDL_Point left;

  bottom.x = center_position.x;
  bottom.y = center_position.y + 1;
  right.x = center_position.x + 1;
  right.y = center_position.y;
  left.x = center_position.x - 1;
  left.y = center_position.y;

  T.emplace_back(center_position);
  T.emplace_back(bottom);
  T.emplace_back(right);
  T.emplace_back(left);

  return T;
}

std::vector<SDL_Point> Obstacle::MakeI() {
  std::vector<SDL_Point> I;
  SDL_Point top;
  SDL_Point bottom;

  top.x = center_position.x;
  top.y = center_position.y + 1;
  bottom.x = center_position.x;
  bottom.y = center_position.y - 1;

  I.emplace_back(center_position);
  I.emplace_back(top);
  I.emplace_back(bottom);

  return I;
}