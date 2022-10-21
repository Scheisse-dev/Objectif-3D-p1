#include "ReservationAddMenu.h"
#include "Utils.h"
#include "DateTime.h"
#include "Client.h"
#include "Booking.h"
#include "BookingManager.h"

#pragma region constructor
ReservationAddMenu::ReservationAddMenu() : Menu("Reservation Add", {})
{
}
#pragma endregion constructor
#pragma region override
void ReservationAddMenu::Open()
{
	Utils::ClearConsole();
	Utils::LogTitle(title);

	const std::string _firstName = Utils::UserStringChoice("client first name: ");
	const std::string _lastName = Utils::UserStringChoice("client last name: ");
	const int _age = Utils::UserChoice<int>("client age: ");
	try
	{
		const DateTime _arrivalDate = DateTime::Parse(Utils::UserStringChoice("arrival date: "));
		const DateTime _departureDate = DateTime::Parse(Utils::UserStringChoice("departure date: "));
		Client* _client = new Client(_firstName, _lastName, _age);
		BookingManager::Instance()->AddBooking(new Booking(_client, _arrivalDate, _departureDate));
	}
	catch (const std::exception& _exception)
	{
		Utils::LogError(_exception.what());
		Utils::Pause();
	}

	Utils::ClearConsole();
	Utils::Log("Booking confirmed !");
	Utils::Pause();
	OpenOldMenu();

}
#pragma endregion override