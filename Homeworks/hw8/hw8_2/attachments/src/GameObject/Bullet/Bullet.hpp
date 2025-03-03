#ifndef BULLET_HPP__
#define BULLET_HPP__

#include <memory>
#include "GameObject.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject;

class Pea : public GameObject {
public:
  Pea(int x, int y, pGameWorld gameWorld);

  virtual void Update();
  void CheckAttack(std::shared_ptr<GameObject> object);
};


class Explosion : public GameObject {
public:
  Explosion(int x, int y, pGameWorld gameWorld);

  virtual void Update();
  void CheckAttack(std::shared_ptr<GameObject> object);
};


#endif // !BULLET_HPP__