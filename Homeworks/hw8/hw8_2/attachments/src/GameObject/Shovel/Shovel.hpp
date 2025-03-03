#ifndef SHOVEL_HPP__
#define SHOVEL_HPP__

#include <memory>
#include "GameObject.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;


class GameObject;


class Shovel : public GameObject {
public:
  Shovel(pGameWorld gameWorld);

  virtual void OnClick();
};


#endif // !SHOVEL_HPP__
