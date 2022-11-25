#pragma once

class Player;
class InputState;

class PlayerManager
{
private:
	Player* player_ = nullptr;
public:
	void ChangeAnimation(Player* player);
	void Update(const InputState& input);
	void Draw();
};

