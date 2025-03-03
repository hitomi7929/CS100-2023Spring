#ifndef PLANTINGSPOT_HPP__
#define PLANTINGSPOT_HPP__

#include <memory>
#include "GameObject.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject;

class PlantingSpot : public GameObject {
public:
  PlantingSpot(int x, int y, pGameWorld gameWorld);

  virtual void OnClick();
};


#endif // !PLANTINGSPOT_HPP__
