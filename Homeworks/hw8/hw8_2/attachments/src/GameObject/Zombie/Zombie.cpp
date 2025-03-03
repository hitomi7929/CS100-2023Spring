#include "Zombie.hpp"
#include "GameWorld.hpp"


Zombie::Zombie(pGameWorld gameWorld) : GameObject::GameObject(IMGID_REGULAR_ZOMBIE, 0, 0, LAYER_ZOMBIES, 20, 80, ANIMID_WALK_ANIM, gameWorld) {
    SetObjectType(Object::Zombie);
    MoveTo(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0, 4) * LAWN_GRID_HEIGHT);
}

void Zombie::Update() {
    if (GetHP() > 0) {
        CheckHP();
        if (GetCurrentAnimation() == ANIMID_WALK_ANIM) {
            MoveTo(GetX() - 1, GetY());
        } else {
            Check();
        }
        if (GetX() < 0) {
            GetWorld() -> SetOver(true);
        }
    }
}

void Zombie::CheckHP() {
    return;
}


RegularZombie::RegularZombie(pGameWorld gameWorld) : Zombie::Zombie(gameWorld) {
    SetHP(200);
}

void RegularZombie::Check() {
    return;
}


BucketHeadZombie::BucketHeadZombie(pGameWorld gameWorld) : RegularZombie::RegularZombie(gameWorld) {
    ChangeImage(IMGID_BUCKET_HEAD_ZOMBIE);
    SetHP(1300);
}

void BucketHeadZombie::CheckHP() {
    if (GetHP() <= 200) {
        ChangeImage(IMGID_REGULAR_ZOMBIE);
    }
}


PoleVaultingZombie::PoleVaultingZombie(pGameWorld gameWorld) : Zombie::Zombie(gameWorld) {
    ChangeImage(IMGID_POLE_VAULTING_ZOMBIE);
    PlayAnimation(ANIMID_RUN_ANIM);
    SetHP(340);
}

void PoleVaultingZombie::Check() {
    if (GetCurrentAnimation() == ANIMID_RUN_ANIM) {
        MoveTo(GetX() - 40, GetY());
        GetWorld() -> CheckJump(shared_from_this());
        MoveTo(GetX() + 40, GetY());
        if (GetCurrentAnimation() == ANIMID_RUN_ANIM) {
            MoveTo(GetX() - 2, GetY());
        }
    } else if (GetCurrentAnimation() == ANIMID_JUMP_ANIM) {
        SetActionTick(GetActionTick() + 1);
        if (GetActionTick() == 42) {
            PlayAnimation(ANIMID_WALK_ANIM);
            MoveTo(GetX() - 150, GetY());
        }
    }
}