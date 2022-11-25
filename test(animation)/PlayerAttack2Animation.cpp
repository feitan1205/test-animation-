#include "PlayerAttack2Animation.h"
#include "PlayerAttack1Animation.h"
#include "PlayerManager.h"
#include "InputState.h"
#include "PlayerIdleAnimation.h"
#include <DxLib.h>

void PlayerAttack2Animation::Update(const InputState& input) {

	m_count++;

	if (m_count > 18)
	{
		m_count = 0;
	}

	//—§‚¿ƒ‚[ƒVƒ‡ƒ“‚É–ß‚é
	if (m_count == 0) {
		player_.ChangeAnimation(new PlayerIdleAnimation(player_));
		return;
	}
}

void PlayerAttack2Animation::Draw(int X, int Y) {

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
	else if (m_count >= 15) {
		DrawGraph(X, Y, m_handle[5], true);
	}
}