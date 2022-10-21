#include "HomeMenu.h"
#include "MenuItem.h"
#include "ReservationMenu.h"

#pragma region constructor
HomeMenu::HomeMenu() : Menu("Home", {
		new MenuItem("Reservation", "Reservation Gestion", new ReservationMenu())
	})
{
}
#pragma endregion constructor