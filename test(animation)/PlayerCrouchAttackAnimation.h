#pragma once
#include "Player.h"
#include <DxLib.h>
class PlayerCrouchAttackAnimation :
    public Player
{
public:
    PlayerCrouchAttackAnimation(PlayerManager& player) : Player(player), m_count(0), attack2flag(false), disengageflag(false){ SetHandle(); };
    ~PlayerCrouchAttackAnimation() {}
    void SetHandle() { LoadDivGraph("data/CrouchAttack.png", 4, 4, 1, 120, 80, m_handle); }
    void Update(const InputState& input);
    void Draw(int X, int Y);
private:
    int m_count;
    int m_handle[4];
    bool attack2flag;
    bool disengageflag;
};

