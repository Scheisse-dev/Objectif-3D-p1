#include "ReservationMenu.h"
#include "ReservationAddMenu.h"
#include "ReservationRemoveMenu.h"
#include "ReservationDisplayMenu.h"
#include "MenuItem.h"

#pragma region constructor
ReservationMenu::ReservationMenu() : Menu("Reservation", {new MenuItem("Add", "Add new booking !", new ReservationAddMenu()),})
{
	new MenuItem("Add", "Add new booking !", new ReservationAddMenu());
	new MenuItem("Remove", "Remove an booking", new ReservationRemoveMenu());
	new MenuItem("Display Bookings", "Display all bookings", new ReservationDisplayMenu());
}
#pragma endregion constructor
#pragma region override
void ReservationMenu::Open()
{
	Menu::Open(); 
	Update(); 
}
#pragma endregion override
