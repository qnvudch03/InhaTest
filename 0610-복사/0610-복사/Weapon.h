#pragma once

enum WeaponType
{
	Hand = 0,
	Sword = 1,
	Arrow = 2,
	Wand = 3,
	Weapon_Max
};

class Weapon
{
public:
	Weapon() : Type(WeaponType::Hand)
	{

	}

	Weapon(WeaponType Weapon) : Type(Weapon) {}

	//µüÈ÷ ¼Ò¸êÀÚ¿¡¼­ ¹» ¾ÈÇØµµ µÇÀÝ¾Æ??
	~Weapon()
	{

	}

	WeaponType GetWeaponType() { return Type; }
	void SetWeaponType(WeaponType IWepon) { Type = IWepon; }

	int MP = 10;
	int ArrowCount = 10;

private:
	WeaponType Type;
};

