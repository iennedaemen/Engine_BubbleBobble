#pragma once
#include <XInput.h>
#include "Singleton.h"
#include "Command.h"
#include "Controller.h"
#include "structs.h"

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		bool IsPressed(ControllerButton button, int playerNr) const;
		std::shared_ptr<Command> HandleInput(int playerNr);
	private:
		XINPUT_STATE m_CurrentState1{};
		XINPUT_STATE m_CurrentState2{};

		// Commands
		std::shared_ptr<WalkLeftCommand> m_pButtonLeft = std::make_shared<WalkLeftCommand>();
		std::shared_ptr<WalkRightCommand> m_pButtonRight = std::make_shared<WalkRightCommand>();
		std::shared_ptr<WalkUpCommand> m_pButtonUp = std::make_shared<WalkUpCommand>();
		std::shared_ptr<WalkDownCommand> m_pButtonDown = std::make_shared<WalkDownCommand>();
		
		std::shared_ptr<ShootCommand> m_pButtonA = std::make_shared<ShootCommand>();

		// Controllers
		std::shared_ptr<Controller> m_Contoller1 = std::make_shared<Controller>(1);
		std::shared_ptr<Controller> m_Contoller2 = std::make_shared<Controller>(2);
	};

