#pragma once
#include "Menu.h"
class ReservationAddMenu : public Menu
{
#pragma region constructor
public:
	ReservationAddMenu();
#pragma endregion constructor
#pragma region override
public:
	void Open() override;
#pragma endregion override
};

