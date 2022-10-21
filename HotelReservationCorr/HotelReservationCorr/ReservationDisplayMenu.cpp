#include "ReservationDisplayMenu.h"
#include "Utils.h"
#include "Booking.h"
#include "BookingManager.h"

ReservationDisplayMenu::ReservationDisplayMenu() : Menu("All Bookings", {})
{
}

void ReservationDisplayMenu::Open()
{
	Utils::ClearConsole(); 
	Utils::LogTitle(title); 
	std::vector<Booking*> _bookings = BookingManager::Instance()->Bookings(); 
	if (_bookings.size() == 0)
	{
		Utils::Log("No Bookings !");
	}
	else {
		for(Booking* _booking : _bookings)
		{
			Utils::LogSeparator(30);
			Utils::Log(_booking);
			Utils::LogSeparator(30);
	}
		Utils::Pause();
		OpenOlMenu(); 
}
