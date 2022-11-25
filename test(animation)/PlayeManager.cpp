#include "PlayerManager.h"
#include "Player.h"

void PlayerManager::ChangeAnimation(Player* player) {

	if (player_ != nullptr) {
		delete player_;
	}
	player_ = player;

}

void PlayerManager::Update(const InputState& input) {
	player_->Update(input);
}

void PlayerManager::Draw() {
	player_->Draw(player_->GetX(), player_->GetY());
}
