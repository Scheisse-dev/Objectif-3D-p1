#include "ReservationRemoveMenu.h"
#include "BookingManager.h"
#include "Utils.h"
#include "Booking.h"

ReservationRemoveMenu::ReservationRemoveMenu() : Menu("Booking Remove", {})
{
}

void ReservationRemoveMenu::DisplayBookings()
{
	if (bookings.size() == 0)
	{
		Utils::Log("No Bookings !");
		Utils::Pause();
		OpenOldMenu();
		return;
	}
	const size_t _size = bookings.size();
	for (size_t i = 0; i < _size; i++)
	{
		Utils::LogSeparator(30);
		Utils::Log(std::to_string(i + 1) + ": " + bookings[i]->ToString());
		Utils::LogSeparator(30);
	}
}

void ReservationRemoveMenu::Open()
{
	Menu::Open();
	bookings = BookingManager::Instance()->Bookings();
	DisplayBookings();

	char _choice = Utils::UserChoice<char>("which reservation do you want to delete ? (n for cancel)");
	if (std::tolower(_choice) == 'n')
	{
		OpenOldMenu();
		return;
	}
	else if (std::isalpha(_choice))
		throw std::exception("[Reservation Remove Menu] => choice no valid !");

	ConfirmationDelete(_choice);
}

void ReservationRemoveMenu::ConfirmationDelete(char _choice)
{
	int _index = _choice - '0' - 1;
	Utils::ClearConsole();
	Utils::LogSeparator(30);
	Utils::Log(bookings[_index]);
	Utils::LogSeparator(30);

	_choice = Utils::UserChoice<char>("Are you sure to delete ? (y/n)");
	if (std::tolower(_choice) == 'n')
	{
		OpenOldMenu();
		return;
	}
	if (std::tolower(_choice) != 'y')
		throw std::exception("[Reservation Remove Menu] => choice no valid !");

	BookingManager::Instance()->RemoveBooking(bookings[_index]);
	OpenOldMenu();
}

void ReservationRemoveMenu::Close()
{
	bookings.clear();
}
