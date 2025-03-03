#include "PlantingSpot.hpp"
#include "GameWorld.hpp"
#include "Plant.hpp"


PlantingSpot::PlantingSpot(int x, int y, pGameWorld gameWorld) : GameObject::GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, gameWorld) {}

void PlantingSpot::OnClick() {
    switch (GetWorld() -> GetHoldItem()) {
        case HoldItem::SunFlower:
            GetWorld() -> AddObject(std::make_shared<Sunflower> (GetX(), GetY(), GetWorld()));
            break;
        case HoldItem::Peashooter:
            GetWorld() -> AddObject(std::make_shared<Peashooter> (GetX(), GetY(), GetWorld()));
            break;
        case HoldItem::Wallnut:
            GetWorld() -> AddObject(std::make_shared<Wallnut> (GetX(), GetY(), GetWorld()));
            break;
        case HoldItem::CherryBomb:
            GetWorld() -> AddObject(std::make_shared<CherryBomb> (GetX(), GetY(), GetWorld()));
            break;
        case HoldItem::Repeater:
            GetWorld() -> AddObject(std::make_shared<Repeater> (GetX(), GetY(), GetWorld()));
            break;
        default:
            break;
    }
    if (GetWorld() -> GetHoldItem() != HoldItem::Shovel) {
        GetWorld() -> SetHoldItem(HoldItem::None);
    }
}