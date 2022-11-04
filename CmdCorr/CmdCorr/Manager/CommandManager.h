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
	void DisplayAllHelp() const; 
	void DisplayHelp(const std::string& _label);
	void Register(ICommand* _command); 
	void Register(const std::initializer_list<ICommand*>& _commands);
	void ExecuteCommand(const std::string& _label, const std::vector<std::string>& _args);
	void DisplayNotRecognized(const std::string& _label);

#pragma endregion methods
};

