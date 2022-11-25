#include "PlayerCrouchAnimation.h"
#include "PlayerCrouchAttackAnimation.h"
#include "PlayerManager.h"
#include "InputState.h"
#include "PlayerAttack1Animation.h"
#include "PlayerWalkAnimation.h"
#include "PlayerIdleAnimation.h"
#include <DxLib.h>

void PlayerCrouchAnimation::Update(const InputState& input) {
	
	m_count++;

	if (m_count >= 21)
	{
		m_count = 0;
	}

	//しゃがみ攻撃モーション
	if (input.IsTriggered(InputType::attack)) {
		player_.ChangeAnimation(new PlayerCrouchAttackAnimation(player_));
		return;
	}

	//立ちモーションに戻る
	if (input.IsDisengage(InputType::crouch)) {
		player_.ChangeAnimation(new PlayerIdleAnimation(player_));
		return;
	}

	//しゃがみ歩きモーション
	if (input.IsPressed(InputType::run)) {
		player_.ChangeAnimation(new PlayerWalkAnimation(player_));
		return;
	}

}

void PlayerCrouchAnimation::Draw(int X, int Y) {

	if (m_count >= 0 && m_count < 7) {
		DrawGraph(X, Y, m_handle[0], true);

	}
	else if (m_count >= 7 && m_count < 14) {
		DrawGraph(X, Y, m_handle[1], true);
	}
	else if (m_count >= 14) {
		DrawGraph(X, Y, m_handle[2], true);
	}

}