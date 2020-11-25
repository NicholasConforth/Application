#pragma once
#include "../Core/System.h"
#include "SDL.h"
#include <string>

namespace nc
{
	class Renderer : public System
	{
	public:
		virtual bool Startup() override;
		virtual void Shutdown() override;
		virtual void Update() override;

		bool Create(const std::string& name, int width, int hieght);

		void Begin();
		void End();

		friend class Texture;
	private:
		SDL_Window* m_window{ nullptr };
		SDL_Renderer* m_renderer{ nullptr };
		SDL_GLContext m_context;
	};
}