#pragma once
#include "Singleton.h"
#include <vector>

class Booking;

class BookingManager : public Singleton<BookingManager>
{
#pragma region f/p
private:
	std::vector<Booking*> bookings = std::vector<Booking*>();
#pragma endregion f/p
#pragma region constructor
public:
	BookingManager() = default;
#pragma endregion constructor
#pragma region methods
public:
	void Display();
	void AddBooking(Booking* _booking);
	void RemoveBooking(Booking* _booking);
	std::vector<Booking*> Bookings() const;
#pragma endregion methods

};

