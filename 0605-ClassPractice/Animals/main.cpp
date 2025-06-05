// Animals.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "Cat.h"
#include "Dog.h"
#include "Rabbit.h"

int main()
{
	Cat* Pet1 = new Cat("야옹이");
	Dog* Pet2 = new Dog("멍멍이");
	Rabbit* Pet3 = new Rabbit("하양이");


	//소멸자는 동적 메모리 delete 처럼 원할 때 호출할 수는 없나??
	/*Cat TestCat("애용");
	~TestCat;*/

	Animal* Animals[6];
	Animals[0] = Pet1;

}

