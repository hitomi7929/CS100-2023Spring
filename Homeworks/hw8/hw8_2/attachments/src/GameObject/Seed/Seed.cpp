#include "Seed.hpp"
#include "GameWorld.hpp"
#include "CooldownMask.hpp"


Seed::Seed(pGameWorld gameWorld) : GameObject::GameObject(IMGID_SEED_SUNFLOWER, 0, 0, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, gameWorld) {}

void Seed::OnClick() {
    if (GetWorld() -> GetHoldItem() == HoldItem::None && GetWorld() -> GetSun() >= GetPrice()) {
        GetWorld() -> SetSun(GetWorld() -> GetSun() - GetPrice());
        GetWorld() -> SetHoldItem(GetItem());
        GetWorld() -> AddObject(std::make_shared<CooldownMask> (GetX(), GetY(), GetWorld(), GetColdTick()));
    }
}

void Seed::SetPrice(int price) {
    m_price = price;
}

int Seed::GetPrice() {
    return m_price;
}

void Seed::SetColdTick(int tick) {
    m_coldtick = tick;
}

int Seed::GetColdTick() {
    return m_coldtick;
}

void Seed::SetItem(HoldItem item) {
    m_item = item;
}

HoldItem Seed::GetItem() {
    return m_item;
}


SunflowerSeed::SunflowerSeed(pGameWorld gameWorld) :Seed::Seed(gameWorld) {
    SetPrice(50);
    SetColdTick(240);
    SetItem(HoldItem::SunFlower);
    MoveTo(130, WINDOW_HEIGHT - 44);
}


PeashooterSeed::PeashooterSeed(pGameWorld gameWorld) :Seed::Seed(gameWorld) {
    SetPrice(100);
    SetColdTick(240);
    SetItem(HoldItem::Peashooter);
    ChangeImage(IMGID_SEED_PEASHOOTER);
    MoveTo(190, WINDOW_HEIGHT - 44);
}


WallnutSeed::WallnutSeed(pGameWorld gameWorld) :Seed::Seed(gameWorld) {
    SetPrice(50);
    SetColdTick(900);
    SetItem(HoldItem::Wallnut);
    ChangeImage(IMGID_SEED_WALLNUT);
    MoveTo(250, WINDOW_HEIGHT - 44);
}


CherryBombSeed::CherryBombSeed(pGameWorld gameWorld) :Seed::Seed(gameWorld) {
    SetPrice(150);
    SetColdTick(1200);
    SetItem(HoldItem::CherryBomb);
    ChangeImage(IMGID_SEED_CHERRY_BOMB);
    MoveTo(310, WINDOW_HEIGHT - 44);
}


RepeaterSeed::RepeaterSeed(pGameWorld gameWorld) :Seed::Seed(gameWorld) {
    SetPrice(200);
    SetColdTick(240);
    SetItem(HoldItem::Repeater);
    ChangeImage(IMGID_SEED_REPEATER);
    MoveTo(370, WINDOW_HEIGHT - 44);
}