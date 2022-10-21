#pragma once
#include "Menu.h"

class Booking;

class ReservationRemoveMenu : public Menu
{
#pragma region f/p
private:
	std::vector<Booking*> bookings = std::vector<Booking*>();
#pragma endregion f/P
#pragma region constructor
public:
	ReservationRemoveMenu();
#pragma endregion constructor
#pragma region methods
public:
	void DisplayBookings();
	void ConfirmationDelete(char _choice);
#pragma endregion methods
#pragma region override
public:
	void Open() override;
	void Close() override;
#pragma endregion override
};

