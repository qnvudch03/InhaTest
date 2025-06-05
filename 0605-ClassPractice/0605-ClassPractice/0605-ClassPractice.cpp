
#include <iostream>

#include "Baby.h"
#include "Student.h"
#include "Adult.h"

int main()
{
	Baby Baby("이", 10);
	Baby.Action();

	Student Student1("이주", 15, "계산고등학교");
	Student1.Action();

	Adult Adult("이주형", 29, "인하대학교");
	Adult.Action();

	Baby.PrintInfo();

	Student1.PrintInfo();

	Adult.PrintInfo();

}
