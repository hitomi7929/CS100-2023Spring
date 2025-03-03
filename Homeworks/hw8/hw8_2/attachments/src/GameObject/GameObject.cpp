#include "GameObject.hpp"


GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld) 
: ObjectBase::ObjectBase(imageID, x, y, layer, width, height, animID), m_hp(100), m_pWorld(gameWorld) {}

void GameObject::Update() {

}

void GameObject::OnClick() {
    
}

pGameWorld GameObject::GetWorld() {
    return m_pWorld;
}

void GameObject::SetHP(int hp) {
    m_hp = hp;
}

int GameObject::GetHP() {
    return m_hp;
}

void GameObject::SetActionTick(int actiontick) {
    m_actiontick = actiontick;
}

int GameObject::GetActionTick() {
    return m_actiontick;
}

void GameObject::SetObjectType(Object object) {
    m_object = object;
}

Object GameObject::GetObjectType() {
    return m_object;
}

void GameObject::CheckAttack(std::shared_ptr<GameObject> object) {
    return;
}