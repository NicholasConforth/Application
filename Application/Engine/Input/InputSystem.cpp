#include "pch.h"
#include "InputSystem.h"

bool nc::InputSystem::Startup()
{
	// get current keystate and retrieve numKeys
	const Uint8* keystate = SDL_GetKeyboardState(&m_numKeys);

	// allocate memory for current and previous keystate
	m_keystate = new Uint8[m_numKeys];
	m_prevKeystate = new Uint8[m_numKeys];
	// copy current keystate (source) to m_keystate (destination)
	memcpy(m_keystate, keystate, m_numKeys);
	// copy current keystate to m_prevKeystate
	memcpy(m_prevKeystate, keystate, m_numKeys);

	return false;
}

void nc::InputSystem::Shutdown()
{
	delete m_keystate;
	delete m_prevKeystate;
}

void nc::InputSystem::Update()
{
	// copy m_keystate (source) to m_prevKeystate (destination)
	memcpy(m_prevKeystate, m_keystate, m_numKeys);
	// get current keystate
	const Uint8* keystate = SDL_GetKeyboardState(nullptr);
	// copy current keystate to m_keystate
	memcpy(m_keystate, keystate, m_numKeys);

}

nc::InputSystem::buttonState nc::InputSystem::GetButtonState(int id)
{
	buttonState state = buttonState::IDLE;

	bool buttonDown = GetButtonDown(id);
	bool prevButtonDown = GetPreviousButtonDown(id);

	if (buttonDown)
	{
		state = (prevButtonDown) ? nc::InputSystem::buttonState::HELD : nc::InputSystem::buttonState::PRESSED;
	}
	else
	{
		state = (prevButtonDown) ? nc::InputSystem::buttonState::RELEASED : nc::InputSystem::buttonState::IDLE;
	}

	return state;

}

bool nc::InputSystem::GetButtonDown(int id)
{
	return m_keystate[id];
}

bool nc::InputSystem::GetPreviousButtonDown(int id)
{
	return m_prevKeystate[id];
}
