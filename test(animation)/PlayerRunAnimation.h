#pragma once
#include "Player.h"
#include <DxLib.h>
class PlayerRunAnimation :
    public Player
{
public:
    PlayerRunAnimation(PlayerManager& player) : Player(player), m_count(0) { SetHandle(); };
    ~PlayerRunAnimation() {}
    void SetHandle() { LoadDivGraph("data/Run.png", 10, 10, 1, 120, 80, m_handle); }
    void Update(const InputState& input);
    void Draw(int X, int Y);
private:
    int m_count;
    int m_handle[10];
};

