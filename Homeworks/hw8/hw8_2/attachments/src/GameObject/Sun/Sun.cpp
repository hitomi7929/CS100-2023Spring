#include "Sun.hpp"
#include "GameWorld.hpp"


Sun::Sun(pGameWorld gameWorld) : GameObject::GameObject(IMGID_SUN, 0, 0, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, gameWorld) {}

void Sun::OnClick() {
    SetHP(0);
    GetWorld() -> SetSun(GetWorld() -> GetSun() + 25);
}


BackgroundSun::BackgroundSun(pGameWorld gameWorld) : Sun::Sun(gameWorld) {
    int x = randInt(75, WINDOW_WIDTH - 75);
    int y = WINDOW_HEIGHT - 1;
    MoveTo(x, y);
    SetActionTick(-1 * randInt(63, 263));
}

void BackgroundSun::Update() {
    if (GetActionTick() < 0) {
        MoveTo(GetX(), GetY() - 2);
    } else if (GetActionTick() == 300) {
        SetHP(0);
    }
    SetActionTick(GetActionTick() + 1);
}


FlowerSun::FlowerSun(int x, int y, pGameWorld gameWorld) : Sun::Sun(gameWorld) {
    MoveTo(x, y);
}

void FlowerSun::Update() {
    SetActionTick(GetActionTick() + 1);
    if (GetActionTick() <= 12) {
        MoveTo(GetX() - 1, GetY() - GetActionTick() + 3);
    } else if (GetActionTick() == 312) {
        SetHP(0);
    }
    
}