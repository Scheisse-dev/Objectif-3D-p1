#pragma once
#include "../Singleton/Singleton.h"
#include <map>
#include <vector>

class ICommand;

class CommandManager : public Singleton<CommandManager>
{
#pragma region f/p
private: 
	std::map<std::string, ICommand*> commands = std::map<std::string, ICommand*>(); 
#pragma endregion f/p
#pragma region constructor/destructor
public:
	CommandManager() = default;
	~CommandManager() override = default; 
#pragma endregion constructor/destructor
#pragma region methods
public: 
	void Register(ICommand* _command); 
	void ExecuteCommand(const std::string& _label, const std::vector<std::string>& _args); 
#pragma endregion methods
};

