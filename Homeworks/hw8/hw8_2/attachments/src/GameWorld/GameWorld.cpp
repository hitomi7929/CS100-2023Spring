#include <ctime>
#include <cmath>
#include "GameWorld.hpp"
#include "Bullet.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init() {
  // YOUR CODE HERE
  SetSun(50);
  SetWave(0);
  SetTick();
  SetNextwave(1200);
  SetOver(false);
  SetHoldItem(HoldItem::None);
  AddObject(std::make_shared<GameObject> (IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this()));
  
  for (int x = 0; x < GAME_COLS; x++) {
    for (int y = 0; y < GAME_ROWS; y++) {
      AddObject(std::make_shared<PlantingSpot> (FIRST_COL_CENTER + x * LAWN_GRID_WIDTH, FIRST_ROW_CENTER + y * LAWN_GRID_HEIGHT, shared_from_this()));
    }
  }
  
  AddObject(std::make_shared<SunflowerSeed> (shared_from_this()));
  AddObject(std::make_shared<PeashooterSeed> (shared_from_this()));
  AddObject(std::make_shared<WallnutSeed> (shared_from_this()));
  AddObject(std::make_shared<CherryBombSeed> (shared_from_this()));
  AddObject(std::make_shared<RepeaterSeed> (shared_from_this()));

  AddObject(std::make_shared<Shovel> (shared_from_this()));
}

LevelStatus GameWorld::Update() {
  // YOUR CODE HERE
  m_tick++;

  if ((m_tick - 180) % 300 == 0) {
    AddObject(std::make_shared<BackgroundSun> (shared_from_this()));
  }

  if (m_tick == m_nextwave) {
    SetWave(GetWave() + 1);
    int num = (15 + GetWave()) / 10;
    int p2 = 2 * std::max(GetWave() - 8, 0);
    int p3 = 3 * std::max(GetWave() - 15, 0);
    int P1 = 20;
    int P2 = P1 + p2;
    int P3 = P2 + p3;
    for (int i = 0; i < num; i++) {
      int p = randInt(1, P3);
      if (p >= 0 && p <= P1) {
        AddObject(std::make_shared<RegularZombie> (shared_from_this()));
      } else if (p > P1 && p <= P2) {
        AddObject(std::make_shared<PoleVaultingZombie> (shared_from_this()));
      } else {
        AddObject(std::make_shared<BucketHeadZombie> (shared_from_this()));
      }
    }
    SetNextwave(GetNextWave() + std::max(150, 600 - 20 * GetWave()));
  }

  for (auto it : m_objects) {
    it -> Update();
  }

  for (auto it1 : m_objects) {
    if (it1 -> GetObjectType() == Object::Zombie) {
      for (auto it2 : m_objects) {
        if (it2 -> GetObjectType() == Object::Plant) {
          if (abs(it1 -> GetX() - it2 -> GetX()) <= (it1 -> GetWidth() + it2 -> GetWidth()) / 2 && it1 -> GetY() == it2 -> GetY()) {
            if (it1 -> GetCurrentAnimation() != ANIMID_EAT_ANIM) {
              it1 -> PlayAnimation(ANIMID_EAT_ANIM);
            }
            it2 -> SetHP(it2 -> GetHP() -3);
          }
        } else if (it2 -> GetObjectType() == Object::Bullet) {
          it2 -> CheckAttack(it1);
        }
      }
    }
  }

  for (auto it = m_objects.begin(); it != m_objects.end(); ) {
    if ((*it) -> GetHP() <= 0) {
      it = m_objects.erase(it);
    } else {
      ++it;
    }
  }

  if (isOver()) {
    return LevelStatus::LOSING;
  }

  for (auto it1 : m_objects) {
    if (it1 -> GetObjectType() == Object::Zombie && it1 -> GetCurrentAnimation() == ANIMID_EAT_ANIM) {
      bool isEatting = false;
      for (auto it2 : m_objects) {
        if (it2 -> GetObjectType() == Object::Plant) {
          if ((abs(it1 -> GetX() - it2 -> GetX()) <= (it1 -> GetWidth() + it2 -> GetWidth()) / 2) && it1 -> GetY() == it2 -> GetY()) {
            isEatting = true;
            break;
          }
        }
      }
      if (!isEatting) {
        it1 -> PlayAnimation(ANIMID_WALK_ANIM);
      }
    }
  }

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // YOUR CODE HERE
  m_objects.clear();
}

void GameWorld::SetTick() {
  m_tick = 0;
}

int GameWorld::GetTick() {
  return m_tick;
}

void GameWorld::SetNextwave(int wavetick) {
  m_nextwave = wavetick;
}

int GameWorld::GetNextWave() {
  return m_nextwave;
}

void GameWorld::SetOver(bool isOver) {
  m_over = isOver;
}

bool GameWorld::isOver() {
  return m_over;
}

void GameWorld::AddObject(std::shared_ptr<GameObject> object) {
  m_objects.emplace_back(object);
}

void GameWorld::SetHoldItem(HoldItem item) {
  m_holditem = item;
}

HoldItem GameWorld::GetHoldItem() {
  return m_holditem;
}

void GameWorld::CheckJump(std::shared_ptr<GameObject> object) {
  for (auto it : m_objects) {
    if (it -> GetObjectType() == Object::Plant) {
      if (abs(object -> GetX() - it -> GetX()) <= (object -> GetWidth() + it -> GetWidth()) / 2 && object -> GetY() == it -> GetY()) {
        object -> PlayAnimation(ANIMID_JUMP_ANIM);
      }
    }
  }
}

void GameWorld::CheckAttack(std::shared_ptr<GameObject> object) {
  for (auto it : m_objects) {
      if (it -> GetObjectType() == Object::Zombie && it -> GetY() == object -> GetY()) {
          AddObject(std::make_shared<Pea> (object -> GetX() + 30, object -> GetY() + 20, object -> GetWorld()));
          object -> SetActionTick(30);
          break;
      }
  }
}