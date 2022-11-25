#pragma once
#include "Player.h"
#include <DxLib.h>

class PlayerAttack1Animation :
    public Player
{
public:
    PlayerAttack1Animation(PlayerManager& player) : Player(player), m_count(0) , attack2flag(false) { SetHandle(); };
    ~PlayerAttack1Animation() {}
    void SetHandle() { LoadDivGraph("data/Attack.png", 4, 4, 1, 120, 80, m_handle); }
    void Update(const InputState& input);
    void Draw(int X, int Y);
private:
    int m_count;
    int m_handle[4];
    bool attack2flag;
};

