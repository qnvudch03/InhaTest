#include "Item.h"


Color ItemData::GetColor() const
{
	if (grade == ItemGrade::Normal)
		return Color::White;
	if (grade == ItemGrade::Rare)
		return Color::RightBlue;
	if (grade == ItemGrade::Legendary)
		return Color::RightRed;

	return Color::Default;
}
