#ifndef COOLDOWNMASK_HPP__
#define COOLDOWNMASK_HPP__

#include <memory>
#include "GameObject.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject;

class CooldownMask : public GameObject {
public:
  CooldownMask(int x, int y, pGameWorld gameWorld, int hp);

  virtual void Update();
};


#endif // !COOLDOWNMASK_HPP__
