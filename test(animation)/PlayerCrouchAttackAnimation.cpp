#include "PlayerCrouchAttackAnimation.h"
#include "PlayerAttack1Animation.h"
#include "PlayerAttack2Animation.h"
#include "PlayerManager.h"
#include "InputState.h"
#include "PlayerIdleAnimation.h"
#include <DxLib.h>

void PlayerCrouchAttackAnimation::Update(const InputState& input) {

	if ((input.IsDisengage(InputType::attack)) && !disengageflag) {
		disengageflag = true;
	}

	if (!disengageflag) {
		return;
	}

	m_count++;

	if (m_count > 15)
	{
		m_count = 0;
	}

	//UŒ‚2‚É”h¶
	if (m_count >= 12 && attack2flag) {
		player_.ChangeAnimation(new PlayerAttack2Animation(player_));
		return;
	}

	//—§‚¿ƒ‚[ƒVƒ‡ƒ“‚É–ß‚é
	if (m_count == 0) {
		player_.ChangeAnimation(new PlayerIdleAnimation(player_));
		return;
	}

	//UŒ‚2‚É”h¶‚·‚é“ü—Íƒ^ƒCƒ~ƒ“ƒO
	if (m_count >= 10 && m_count <= 14) {
		if (input.IsTriggered(InputType::attack)) {
			attack2flag = true;
		}
	}
}

void PlayerCrouchAttackAnimation::Draw(int X, int Y) {

	if (m_count >= 0 && m_count < 3) {
		DrawGraph(X, Y, m_handle[0], true);

	}
	else if (m_count >= 3 && m_count < 6) {
		DrawGraph(X, Y, m_handle[1], true);
	}
	else if (m_count >= 6 && m_count < 9) {
		DrawGraph(X, Y, m_handle[2], true);
	}
	else if (m_count >= 9) {
		DrawGraph(X, Y, m_handle[3], true);
	}
}