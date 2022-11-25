#include "PlayerWalkAnimation.h"
#include "PlayerIdleAnimation.h"
#include "PlayerManager.h"
#include "InputState.h"
#include "PlayerAttack1Animation.h"
#include "PlayerRunAnimation.h"
#include "PlayerCrouchAnimation.h"
#include <DxLib.h>

void PlayerWalkAnimation::Update(const InputState& input) {

	m_count++;

	if (m_count >= 40)
	{
		m_count = 0;
	}

	//攻撃1モーション
	if (input.IsTriggered(InputType::attack)) {
		player_.ChangeAnimation(new PlayerAttack1Animation(player_));
		return;
	}

	//走りモーション
	if (input.IsDisengage(InputType::crouch)) {
		player_.ChangeAnimation(new PlayerRunAnimation(player_));
		return;
	}

	//しゃがみモーション
	if (input.IsDisengage(InputType::run)) {
		player_.ChangeAnimation(new PlayerCrouchAnimation(player_));
		return;
	}

}

void PlayerWalkAnimation::Draw(int X, int Y) {

	if (m_count >= 0 && m_count < 5) {
		DrawGraph(X, Y, m_handle[0], true);
	}
	else if (m_count >= 5 && m_count < 10) {
		DrawGraph(X, Y, m_handle[1], true);
	}
	else if (m_count >= 10 && m_count < 15) {
		DrawGraph(X, Y, m_handle[2], true);
	}
	else if (m_count >= 15 && m_count < 20) {
		DrawGraph(X, Y, m_handle[3], true);
	}
	else if (m_count >= 20 && m_count < 25) {
		DrawGraph(X, Y, m_handle[4], true);
	}
	else if (m_count >= 25 && m_count < 30) {
		DrawGraph(X, Y, m_handle[5], true);
	}
	else if (m_count >= 30 && m_count < 35) {
		DrawGraph(X, Y, m_handle[6], true);
	}
	else if (m_count >= 35) {
		DrawGraph(X, Y, m_handle[7], true);
	}

}