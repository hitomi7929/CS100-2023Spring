#include "Bullet.hpp"
#include "GameWorld.hpp"


Pea::Pea(int x, int y, pGameWorld gameWorld) : GameObject::GameObject(IMGID_PEA, x, y, LAYER_PROJECTILES, 28, 28, ANIMID_NO_ANIMATION, gameWorld) {
    SetObjectType(Object::Bullet);
}

void Pea::Update() {
    if (GetHP() > 0) {
        MoveTo(GetX() + 8, GetY());
    }
    if (GetX() >= WINDOW_WIDTH) {
        SetHP(0);
    }
}

void Pea::CheckAttack(std::shared_ptr<GameObject> object) {
    if (abs(object -> GetX() - shared_from_this() -> GetX()) <= (object -> GetWidth() + shared_from_this() -> GetWidth()) / 2 && (abs(shared_from_this() -> GetY() - object -> GetY()) <= (object -> GetHeight() + shared_from_this() -> GetHeight()) / 2)) {
        object -> SetHP(object -> GetHP() - 20);
        shared_from_this() -> SetHP(0);
    }
}


Explosion::Explosion(int x, int y, pGameWorld gameWorld) : GameObject::GameObject(IMGID_EXPLOSION, x, y, LAYER_PROJECTILES, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION, gameWorld) {
    SetHP(3);
    SetObjectType(Object::Bullet);
}

void Explosion::Update() {
    SetHP(GetHP() - 1);
}

void Explosion::CheckAttack(std::shared_ptr<GameObject> object) {
    if ((abs(object -> GetX() - shared_from_this() -> GetX()) <= (object -> GetWidth() + shared_from_this() -> GetWidth()) / 2) && (abs(shared_from_this() -> GetY() - object -> GetY()) <= (object -> GetHeight() + shared_from_this() -> GetHeight()) / 2)) {
        object -> SetHP(0);
    }
}