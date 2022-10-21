#pragma once
#include "Object.h"
#include "DateTime.h"

class Client;

class Booking : public Object
{
#pragma region f/p
private:
	Client* client = nullptr;
	DateTime arrivalDate = DateTime();
	DateTime departureDate = DateTime();
#pragma endregion f/p
#pragma region constructor
public:
	Booking() = default;
	Booking(Client* _client, DateTime _arrival, DateTime _departure);
	Booking(const Booking& _copy);
	~Booking() override;
#pragma endregion constructor
#pragma region methods
public:
	Client* GetClient() const;
	DateTime ArrivalDate() const;
	DateTime DepartureDate() const;
#pragma endregion methods
#pragma region override
public:
	std::string ToString() const override;
#pragma endregion override


};

