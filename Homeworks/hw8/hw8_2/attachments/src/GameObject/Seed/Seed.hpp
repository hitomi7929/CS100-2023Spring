#ifndef SEED_HPP__
#define SEED_HPP__

#include <memory>
#include "GameObject.hpp"
#include "HoldItem.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject;

class Seed : public GameObject {
public:
  Seed(pGameWorld gameWorld);

  virtual void OnClick();

  void SetPrice(int price);
  int GetPrice();

  void SetColdTick(int tick);
  int GetColdTick();

  void SetItem(HoldItem item);
  HoldItem GetItem();

private:
  int m_price;
  int m_coldtick;
  HoldItem m_item = HoldItem::None;
};


class SunflowerSeed : public Seed {
public:
  SunflowerSeed(pGameWorld gameWorld);
};


class PeashooterSeed : public Seed {
public:
  PeashooterSeed(pGameWorld gameWorld);
};


class WallnutSeed : public Seed {
public:
  WallnutSeed(pGameWorld gameWorld);
};


class CherryBombSeed : public Seed {
public:
  CherryBombSeed(pGameWorld gameWorld);
};


class RepeaterSeed : public Seed {
public:
  RepeaterSeed(pGameWorld gameWorld);
};


#endif // !SEED_HPP__
