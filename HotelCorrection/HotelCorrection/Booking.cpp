#include "Booking.h"
#include "Client.h"
#include <format>

#pragma region constructor
Booking::Booking(Client* _client, DateTime _arrival, DateTime _departure)
{
	client = _client;
	arrivalDate = _arrival;
	departureDate = _departure;
}

Booking::Booking(const Booking& _copy)
{
	client = _copy.client;
	arrivalDate = _copy.arrivalDate;
	departureDate = _copy.departureDate;
}

Booking::~Booking()
{
	delete client;
}
#pragma endregion constructor
#pragma region methods
Client* Booking::GetClient() const
{
	return client;
}

DateTime Booking::ArrivalDate() const
{
	return arrivalDate;
}

DateTime Booking::DepartureDate() const
{
	return departureDate;
}
#pragma endregion methods
#pragma region override
std::string Booking::ToString() const
{
	return std::format("Client:\n{}\nArrival Date: {}\nDeparture Date: {}", client->ToString(),
		arrivalDate.ToString(), departureDate.ToString());
}
#pragma endregion override