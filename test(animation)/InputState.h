#pragma once

enum class InputType {
	attack,	//�U���{�^��
	dash,	//��������{�^��
	run,	//����{�^��
	crouch	//���Ⴊ�ރ{�^��
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

