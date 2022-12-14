#include "PlayerRunAnimation.h"
#include "PlayerManager.h"
#include "InputState.h"
#include "PlayerAttack1Animation.h"
#include "PlayerIdleAnimation.h"
#include "PlayerWalkAnimation.h"
#include <DxLib.h>

void PlayerRunAnimation::Update(const InputState& input) {

	m_count++;

	if (m_count >= 30)
	{
		m_count = 0;
	}

	//立ちモーションに戻る
	if (input.IsDisengage(InputType::run)) {
		player_.ChangeAnimation(new PlayerIdleAnimation(player_));
	}

	//攻撃1モーション
	if (input.IsTriggered(InputType::attack)) {
		player_.ChangeAnimation(new PlayerAttack1Animation(player_));
		return;
	}

	//しゃがみ歩きモーション
	if (input.IsPressed(InputType::crouch)) {
		player_.ChangeAnimation(new PlayerWalkAnimation(player_));
		return;
	}

}

void PlayerRunAnimation::Draw(int X, int Y) {

	if (m_count >= 0 && m_count < 3) {
		DrawGraph(X, Y, m_handle[0], true);
	}
	else if (m_count >= 3 && m_count < 6) {
		DrawGraph(X, Y, m_handle[1], true);
	}
	else if (m_count >= 6 && m_count < 9) {
		DrawGraph(X, Y, m_handle[2], true);
	}
	else if (m_count >= 9 && m_count < 12) {
		DrawGraph(X, Y, m_handle[3], true);
	}
	else if (m_count >= 12 && m_count < 15) {
		DrawGraph(X, Y, m_handle[4], true);
	}
	else if (m_count >= 15 && m_count < 18) {
		DrawGraph(X, Y, m_handle[5], true);
	}
	else if (m_count >= 18 && m_count < 21) {
		DrawGraph(X, Y, m_handle[6], true);
	}
	else if (m_count >= 21 && m_count < 24) {
		DrawGraph(X, Y, m_handle[7], true);
	}
	else if (m_count >= 24 && m_count < 27) {
		DrawGraph(X, Y, m_handle[8], true);
	}
	else if (m_count >= 27) {
		DrawGraph(X, Y, m_handle[9], true);
	}
}