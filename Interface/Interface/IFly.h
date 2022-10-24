#pragma once
//une interface ne contient aucune variable != class abstract
#ifdef _WIN32 || _WIN64
__interface IFly
{
public:
	void Fly();
	float Speed();
};

#elif __APPLE__ || __linux__
class IFly
{
	
public:
	virtual ~IFly() = default;
	virtual void Fly() = 0;
	virtual float Speed() = 0;
};
#endif


