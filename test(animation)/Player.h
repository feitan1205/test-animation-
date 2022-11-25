#pragma once
class PlayerManager;
class InputState;
class Player
{
protected:
	PlayerManager& player_;
private:
	int X, Y;
public:
	Player(PlayerManager& player) :player_(player) ,X(50),Y(50) {}
	virtual ~Player() {};
	//シーンを更新する
	virtual void Update(const InputState& input) = 0;
	//シーンを描画する
	virtual void Draw(int X, int Y) = 0;
public:
	int GetX() { return X; }
	int GetY() { return Y; }
};

