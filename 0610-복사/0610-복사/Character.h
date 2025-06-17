#pragma once

#include "Weapon.h"
//class Weapon;

enum WarriorClassType
{
	None = 0,
	Hearo = 1,
	Archor = 2,
	Mage = 3,
	TypeMax
};

class Character
{
public:
	Character() : WarriorClass(WarriorClassType::None), equipWeapon(nullptr)
	{
		equipWeapon = new Weapon();
	}

	virtual ~Character()
	{
		if (equipWeapon)
		{
			delete equipWeapon;
		}
	}

	Character(const Character& other) : WarriorClass(WarriorClassType::None), equipWeapon(nullptr)
	{
		equipWeapon = new Weapon();
		equipWeapon->SetWeaponType(other.equipWeapon->GetWeaponType());
	}

	Character& operator=(Character& Target)
	{
		equipWeapon = new Weapon();
		equipWeapon->SetWeaponType(Target.equipWeapon->GetWeaponType());

		return Target;
	}

	void EquipWeapon(Weapon Weapon);
	virtual void Attack();

	WarriorClassType GetWarriorClassType() { return WarriorClass; }
	Weapon* GetequipWeapon() { return equipWeapon; }

public:
	WarriorClassType WarriorClass;
	Weapon* equipWeapon;
};

