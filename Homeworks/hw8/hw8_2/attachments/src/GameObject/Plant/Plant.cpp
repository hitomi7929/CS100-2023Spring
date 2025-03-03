#include "Plant.hpp"
#include "GameWorld.hpp"
#include "Bullet.hpp"


Plant::Plant(int x, int y, pGameWorld gameWorld) : GameObject::GameObject(IMGID_SUNFLOWER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, gameWorld) {
    SetObjectType(Object::Plant);
}

void Plant::OnClick() {
    if (GetWorld() -> GetHoldItem() == HoldItem::Shovel) {
        SetHP(0);
        GetWorld() -> SetHoldItem(HoldItem::None);
    }
}


Sunflower::Sunflower(int x, int y, pGameWorld gameWorld) : Plant::Plant(x, y, gameWorld) {
    SetActionTick(-1 * randInt(30, 600));
    SetHP(300);
}

void Sunflower::Update() {
    SetActionTick(GetActionTick() + 1);
    if (GetActionTick() % 600 == 0 && GetHP() > 0) {
        GetWorld() -> AddObject(std::make_shared<FlowerSun> (GetX(), GetY(), GetWorld()));
    }
}


Peashooter::Peashooter(int x, int y, pGameWorld gameWorld) : Plant::Plant(x, y, gameWorld) {
    ChangeImage(IMGID_PEASHOOTER);
    SetHP(300);
}

void Peashooter::Update() {
    if (GetHP() > 0) {
        if (GetActionTick() > 0) {
            SetActionTick(GetActionTick() - 1);
            CheckRepeatAttack();
        } else {
            GetWorld() -> CheckAttack(shared_from_this());
        }
    }
}

void Peashooter::CheckRepeatAttack() {
    return;
}


Wallnut::Wallnut(int x, int y, pGameWorld gameWorld) : Plant::Plant(x, y, gameWorld) {
    ChangeImage(IMGID_WALLNUT);
    SetHP(4000);
}

void Wallnut::Update() {
    if (GetHP() <= 1333) {
        ChangeImage(IMGID_WALLNUT_CRACKED);
    }
}


CherryBomb::CherryBomb(int x, int y, pGameWorld gameWorld) : Plant::Plant(x, y, gameWorld) {
    ChangeImage(IMGID_CHERRY_BOMB);
    SetHP(4000);
    SetActionTick(15);
}

void CherryBomb::Update() {
    SetActionTick(GetActionTick() - 1);
    if (GetActionTick() == 0) {
        SetHP(0);
        GetWorld() -> AddObject(std::make_shared<Explosion> (GetX(), GetY(), GetWorld()));
    }
}


Repeater::Repeater(int x, int y, pGameWorld gameWorld) : Peashooter::Peashooter(x, y, gameWorld) {
    ChangeImage(IMGID_REPEATER);
}


void Repeater::CheckRepeatAttack() {
    if (GetActionTick() == 25) {
        GetWorld() -> AddObject(std::make_shared<Pea> (GetX() + 30, GetY() + 20, GetWorld()));
    }
}