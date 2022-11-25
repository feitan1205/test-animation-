#include "InputState.h"
#include <DxLib.h>

void InputState::Update() {
	for (int i = 0; i < _countof(lastKeystate); ++i) {
		lastKeystate[i] = keystate[i];
	}
	GetHitKeyStateAll(keystate);
}

bool InputState::IsPressed(InputType type)const {
	if (type == InputType::attack) {
		return lastKeystate[KEY_INPUT_SPACE];
	}
	if (type == InputType::dash) {
		if (CheckHitKey(KEY_INPUT_LSHIFT)) {
			return  true;
		}
	}
	if (type == InputType::run) {
		if (CheckHitKey(KEY_INPUT_D)) {
			return  true;
		}
	}
	if (type == InputType::crouch) {
		if (CheckHitKey(KEY_INPUT_LCONTROL)) {
			return  true;
		}
	}
	return false;
}

bool InputState::IsTriggered(InputType type)const {
	if (type == InputType::attack) {
		return !lastKeystate[KEY_INPUT_SPACE] &&
			keystate[KEY_INPUT_SPACE];
	}
	if (type == InputType::dash) {
		return !lastKeystate[KEY_INPUT_LSHIFT] &&
			keystate[KEY_INPUT_LSHIFT];
	}
	if (type == InputType::run) {
		return !lastKeystate[KEY_INPUT_D] &&
			keystate[KEY_INPUT_D];
	}
	if (type == InputType::crouch) {
		return !lastKeystate[KEY_INPUT_LCONTROL] &&
			keystate[KEY_INPUT_LCONTROL];
	}
	return false;
}

bool InputState::IsDisengage(InputType type)const{
	if (type == InputType::attack) {
		return lastKeystate[KEY_INPUT_SPACE] &&
			!keystate[KEY_INPUT_SPACE];
	}
	if (type == InputType::dash) {
		return lastKeystate[KEY_INPUT_LSHIFT] &&
			!keystate[KEY_INPUT_LSHIFT];
	}
	if (type == InputType::run) {
		return lastKeystate[KEY_INPUT_D] &&
			!keystate[KEY_INPUT_D];
	}
	if (type == InputType::crouch) {
		return lastKeystate[KEY_INPUT_LCONTROL] &&
			!keystate[KEY_INPUT_LCONTROL];
	}
	return false;
}