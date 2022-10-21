#pragma once
#include "Menu.h"
class ReservationDisplayMenu : public Menu
{
#pragma region constructor
public:
	ReservationDisplayMenu();
#pragma endregion constructor
#pragma region override
public:
	void Open() override;
#pragma endregion override
};

