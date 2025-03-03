#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"
#include "Object.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".

  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld);
  
  virtual void Update();
  virtual void OnClick();

  pGameWorld GetWorld();
  
  void SetHP(int hp);
  int GetHP();

  void SetActionTick(int actiontick);
  int GetActionTick();

  void SetObjectType(Object object);
  Object GetObjectType();

  virtual void CheckAttack(std::shared_ptr<GameObject> object);

private:
  int m_hp;
  int m_actiontick = 0;
  Object m_object = Object::Default;
  pGameWorld m_pWorld;
};


#endif // !GAMEOBJECT_HPP__
