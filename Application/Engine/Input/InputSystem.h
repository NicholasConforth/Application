#pragma once
#include "../Core/System.h"

namespace nc
{
	class InputSystem : public System
	{
	public:
		enum class buttonState
		{
			IDLE,
			PRESSED,
			HELD,
			RELEASED
		};

		virtual bool Startup() override;
		virtual void Shutdown() override;
		virtual void Update() override;

		buttonState GetButtonState(int id);
		bool GetButtonDown(int id);
		bool GetPreviousButtonDown(int id);

	protected:
		Uint8* m_keystate;
		Uint8* m_prevKeystate;
		int m_numKeys;

	};
}