#include "obstacle.h"

std::vector<SDL_Point> Obstacle::MakeObstacle() {
  std::vector<SDL_Point> obstacle;
  switch (shape) {
    case Shape::L:
      MakeL();
      break;
    case Shape::T:
      MakeT();
      break;
    case Shape::I:
      MakeI();
      break;
  }
  return obstacle;
}

std::vector<SDL_Point> Obstacle::MakeL() {
  std::vector<SDL_Point> L;
  SDL_Point top;
  SDL_Point right;

  top.x = center_position.x;        // TODO
  top.y = center_position.y + 1;    // TODO
  right.x = center_position.x + 1;  // TODO
  right.y = center_position.y;      // TODO

  L.emplace_back(center_position);
  L.emplace_back(top);
  L.emplace_back(right);

  return L;
}

std::vector<SDL_Point> Obstacle::MakeT() {
  std::vector<SDL_Point> T;
  SDL_Point left;
  SDL_Point right;
  SDL_Point bottom;

  left.x = center_position.x - 1;    // TODO
  left.x = center_position.y;        // TODO
  right.x = center_position.x + 1;   // TODO
  right.x = center_position.y;       // TODO
  bottom.x = center_position.x;      // TODO
  bottom.x = center_position.y + 1;  // TODO
  bottom.x = center_position.y + 1;  // TODO

  T.emplace_back(center_position);
  T.emplace_back(left);
  T.emplace_back(right);
  T.emplace_back(bottom);

  return T;
}

std::vector<SDL_Point> Obstacle::MakeI() {
  std::vector<SDL_Point> I;
  SDL_Point top;
  SDL_Point bottom;

  top.x = center_position.x;         // TODO
  top.y = center_position.y + 1;     // TODO
  bottom.x = center_position.x;      // TODO
  bottom.y = center_position.y - 1;  // TODO

  I.emplace_back(center_position);
  I.emplace_back(top);
  I.emplace_back(bottom);

  return I;
}