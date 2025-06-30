#ifndef ENEMY_H
#define ENEMY_H

#include "Engine/Game/Game.hpp"
#include "Engine/Entity/Entity.hpp"

extern Game game;

class Enemy : public Entity
{
public:    
    Enemy(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif