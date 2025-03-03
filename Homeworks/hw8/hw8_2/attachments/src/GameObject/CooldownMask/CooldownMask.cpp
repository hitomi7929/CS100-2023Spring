#include "CooldownMask.hpp"


CooldownMask::CooldownMask(int x, int y, pGameWorld gameWorld, int hp) : GameObject::GameObject(IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50, 70, ANIMID_NO_ANIMATION, gameWorld) {
    SetHP(hp);
}

void CooldownMask::Update() {
    SetHP(GetHP() - 1);
}