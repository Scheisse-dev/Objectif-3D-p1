#include "BookingManager.h"
#include "Utils.h"
#include "Booking.h"; 

#pragma region methods 
void BookingManager::Display()
{
	Utils::LogTitle("All Bookings"); 
	for(Booking * _booking : booking)
	{
		Utils::LogSeparator(20); 
		Utils::Log(_booking);
		Utils::LogSeparator(20); 
	}
}

void BookingManager::AddBooking(Booking* _booking)
{
	booking.push_back(_booking); 
}

void BookingManager::RemoveBooking(Booking* _booking)
{
	const size_t _size = booking.size(); 
	for (size_t i = 0; i < _size; i++)
	{
		if (booking[i] == _booking)
		{
			booking.erase(booking.begin() + i); 
			delete _booking;
			break; 
		}
	}
}

std::vector<Booking*> BookingManager::Bookings() const
{
	return booking;
}
#pragma endregion methods 