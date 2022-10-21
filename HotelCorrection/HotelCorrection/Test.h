#pragma once
#include <vector>
#include <string>

class Test
{
private:
	static inline Test* instance = nullptr;
	std::vector<std::string> clients = std::vector<std::string>();
public:
	Test() = default;
	static Test* Instance()
	{
		if (instance == nullptr)
			instance = new Test();
		return instance;
	}

	void AddClient(const std::string& _client)
	{
		clients.push_back(_client);
	}
	std::vector<std::string> Clients() const { return clients;}
};

