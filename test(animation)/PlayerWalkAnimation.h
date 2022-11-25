#pragma once
#include "Player.h"
#include <DxLib.h>

class PlayerWalkAnimation :
    public Player
{
public:
    PlayerWalkAnimation(PlayerManager& player) : Player(player), m_count(0) { SetHandle(); };
    ~PlayerWalkAnimation() {}
    void SetHandle() { LoadDivGraph("data/Walk.png", 8, 8, 1, 120, 80, m_handle); }
    void Update(const InputState& input);
    void Draw(int X, int Y);
private:
    int m_count;
    int m_handle[8];
};

