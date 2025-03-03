#include "Shovel.hpp"
#include "GameWorld.hpp"


Shovel::Shovel(pGameWorld gameWorld) : GameObject::GameObject(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION, gameWorld) {}

void Shovel::OnClick() {
    if (GetWorld() -> GetHoldItem() == HoldItem::Shovel) {
        GetWorld() -> SetHoldItem(HoldItem::None);
    } else if (GetWorld() -> GetHoldItem() == HoldItem::None) {
        GetWorld() -> SetHoldItem(HoldItem::Shovel);
    }
}