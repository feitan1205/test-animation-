#pragma once

enum class InputType {
	attack,	//攻撃ボタン
	dash,	//速く走るボタン
	run,	//走るボタン
	crouch	//しゃがむボタン
};

class InputState
{
private:
	int keypadState;
	int lastKeypadState;
	char keystate[256];
	char lastKeystate[256];
public:
	bool IsTriggered(InputType type)const;
	bool IsPressed(InputType type)const;
	bool IsDisengage(InputType type)const;
	void Update();
};

