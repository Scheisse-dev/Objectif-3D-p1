#include "ReservationMenu.h"
#include "MenuItem.h"
#include "ReservationAddMenu.h"
#include "ReservationDisplayMenu.h"
#include "ReservationRemoveMenu.h"

#pragma region constructor
ReservationMenu::ReservationMenu() : Menu("Reservation",
	{
		new MenuItem("Add", "Add new booking !", new ReservationAddMenu()),
		new MenuItem("Remove", "Remove a booking !", new ReservationRemoveMenu()),
		new MenuItem("Display Bookings", "Display all bookings !", new ReservationDisplayMenu()),
	})
{
}
void ReservationMenu::Open()
{
	Menu::Open();
	Update();
}
#pragma endregion constructor