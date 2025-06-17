#include "Character.h"
#include "Weapon.h"

#include "Warrior.h"
#include "Archor.h"
#include "Mage.h"

#include <iostream>

void Character::EquipWeapon(Weapon IWeapon)
{
	if (equipWeapon)
	{
		delete equipWeapon;
		equipWeapon = nullptr;
	}

	equipWeapon = new Weapon(IWeapon);

}

void Character::Attack()
{
	int WeaponType = equipWeapon->GetWeaponType();
	//Character* AttackPtr = nullptr;

	switch (WeaponType)
	{
	case WeaponType::Hand:
		std::cout << "맨손 공격!\n";
		break;

	case WeaponType::Sword:
		std::cout << "검 공격!\n";
		break;

	case WeaponType::Arrow:
		std::cout << "활 공격!\n";
		equipWeapon->ArrowCount--;
		break;

	case WeaponType::Wand:
		AttackPtr = (MageClass*)this;
		std::cout << "마법 공격!\n";
		equipWeapon->MP--;
		break;
	default:
		break;
	}
}
