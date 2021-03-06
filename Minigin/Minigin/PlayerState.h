#pragma once
#include "structs.h"
#include <SDL_hints.h>
class Player;

class PlayerState
{
public:
   // static WalkingState walking;
   // static ShootingState shooting;
	
    virtual ~PlayerState() {}
    virtual std::shared_ptr<PlayerState> handleInput(Player& player, Uint8 input = 0)
    {
        UNREFERENCED_PARAMETER(player);
        UNREFERENCED_PARAMETER(input);
        return nullptr;
    };
    virtual void update(Player& player)
    {
        UNREFERENCED_PARAMETER(player);
    }

};

class IdleState : public PlayerState
{
public:
    IdleState() {}

    virtual std::shared_ptr<PlayerState> handleInput(Player& player, Uint8 input = 0) override;

};

class WalkingState : public PlayerState
{
public:
    WalkingState() {}

    virtual std::shared_ptr<PlayerState> handleInput(Player& player, Uint8 input = 0) override;

};

class ShootingState : public PlayerState
{
public:
    ShootingState() {}

    virtual std::shared_ptr<PlayerState> handleInput(Player& player, Uint8 input = 0) override;

};