#pragma once
#include "Player.h"
#include <DxLib.h>
class PlayerAttack2Animation :
    public Player
{
public:
    PlayerAttack2Animation(PlayerManager& player) : Player(player), m_count(0) { SetHandle(); };
    ~PlayerAttack2Animation() {}
    void SetHandle() { LoadDivGraph("data/Attack2.png", 6, 6, 1, 120, 80, m_handle); }
    void Update(const InputState& input);
    void Draw(int X, int Y);
private:
    int m_count;
    int m_handle[6];
};

