#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"
#include "GameObject.hpp"
#include "Sun.hpp"
#include "PlantingSpot.hpp"
#include "Seed.hpp"
#include "Plant.hpp"
#include "Zombie.hpp"
#include "Shovel.hpp"
#include "HoldItem.hpp"
#include "utils.hpp"


class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this".
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  void SetTick();
  int GetTick();

  void SetNextwave(int wavetick);
  int GetNextWave();

  void SetOver(bool isOver);
  bool isOver();

  void AddObject(std::shared_ptr<GameObject> object);

  void SetHoldItem(HoldItem item);
  HoldItem GetHoldItem();

  void CheckJump(std::shared_ptr<GameObject> object);
  void CheckAttack(std::shared_ptr<GameObject> object);

private: 
  int m_tick = 0;
  int m_nextwave = 1200;
  bool m_over = false;
  std::list<std::shared_ptr<GameObject>> m_objects;
  HoldItem m_holditem = HoldItem::None;
};

#endif // !GAMEWORLD_HPP__
