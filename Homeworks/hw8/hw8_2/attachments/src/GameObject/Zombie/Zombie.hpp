#ifndef ZOMBIE_HPP__
#define ZOMBIE_HPP__

#include <memory>
#include "GameObject.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject;

class Zombie : public GameObject {
public:
  Zombie(pGameWorld gameWorld);

  virtual void Update();
  virtual void Check() = 0;
  virtual void CheckHP();
};


class RegularZombie : public Zombie {
public:
  RegularZombie(pGameWorld gameWorld);

  virtual void Check();
};


class BucketHeadZombie : public RegularZombie {
public:
  BucketHeadZombie(pGameWorld gameWorld);

  virtual void CheckHP();
};


class PoleVaultingZombie : public Zombie {
public:
  PoleVaultingZombie(pGameWorld gameWorld);

  virtual void Check();
};

#endif // !ZOMBIE_HPP__