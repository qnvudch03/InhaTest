#include "MyHelper.h"

void ChangItemGradFromGrad(ItemData* Item)
{
	if (Item->grade == ItemGrade::Normal)
	{
		SetCursorColor(Color::White);
	}

	else if (Item->grade == ItemGrade::Rare)
	{
		SetCursorColor(Color::SkyBlue);
	}

	else if (Item->grade == ItemGrade::Legendary)
	{
		SetCursorColor(Color::Red);
	}
}
