#ifndef PLAYER_H
#define PLAYER_H

#include "Engine/Game/Game.hpp"
#include "Engine/Entity/Entity.hpp"

extern Game game;

class Player : public Entity
{
public:    
    Rectangle* current_axe_hitbox;

    Player(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void Init() override;
    void Update() override;
    void Draw() override;
};

#endif