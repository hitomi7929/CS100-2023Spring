#ifndef PLANT_HPP__
#define PLANT_HPP__

#include <memory>
#include "GameObject.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject;

class Plant : public GameObject {
public:
  Plant(int x, int y, pGameWorld gameWorld);

  virtual void OnClick();
};


class Sunflower : public Plant {
public:
  Sunflower(int x, int y, pGameWorld gameWorld);

  virtual void Update();
};


class Peashooter : public Plant {
public:
  Peashooter(int x, int y, pGameWorld gameWorld);

  virtual void Update();

  virtual void CheckRepeatAttack();
};


class Wallnut : public Plant {
public:
  Wallnut(int x, int y, pGameWorld gameWorld);

  virtual void Update();
};


class CherryBomb : public Plant {
public:
  CherryBomb(int x, int y, pGameWorld gameWorld);

  virtual void Update();
};


class Repeater : public Peashooter {
public:
  Repeater(int x, int y, pGameWorld gameWorld);

  virtual void CheckRepeatAttack();
};


#endif // !PLANT_HPP__