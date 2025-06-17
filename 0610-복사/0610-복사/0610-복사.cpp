// 0610-복사.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Character.h"
#include "Warrior.h"

int main()
{
    Character* Player = new Character();

    Player->EquipWeapon(WeaponType::Sword);

    Character* Archor = new Character();
    Archor->EquipWeapon(WeaponType::Arrow);

    Character Dummy;
    Dummy.EquipWeapon(WeaponType::Arrow);

    Character Dummy2 = Dummy;

    //Dummy2 = Dummy;

    Dummy2.Attack();

}
