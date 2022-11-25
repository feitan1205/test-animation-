#pragma once
#include "Player.h"
#include <DxLib.h>

class PlayerCrouchAnimation :
    public Player
{
public:
    PlayerCrouchAnimation(PlayerManager& player) : Player(player), m_count(0) { SetHandle(); };
    ~PlayerCrouchAnimation() {}
    void SetHandle() { LoadDivGraph("data/CrouchFull.png", 3, 3, 1, 120, 80, m_handle); }
    void Update(const InputState& input);
    void Draw(int X, int Y);
private:
    int m_count;
    int m_handle[3];
};

