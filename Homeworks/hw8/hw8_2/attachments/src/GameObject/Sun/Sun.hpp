#ifndef SUN_HPP__
#define SUN_HPP__

#include <memory>
#include "GameObject.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;


class GameObject;


class Sun : public GameObject {
public:
  Sun(pGameWorld gameWorld);

  virtual void Update() = 0;
  virtual void OnClick();
};

class BackgroundSun : public Sun {
public:
    BackgroundSun(pGameWorld gameWorld);

    virtual void Update() override;
};

class FlowerSun : public Sun {
public:
  FlowerSun(int x, int y, pGameWorld gameWorld);

  virtual void Update() override;
};


#endif // !SUN_HPP__
