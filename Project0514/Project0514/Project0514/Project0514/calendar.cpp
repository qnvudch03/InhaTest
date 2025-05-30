#include <iostream>

//1���� 31��

struct DateStruct
{
	int Year = 0;
	int Month = 0;
	int Day = 0;

};

DateStruct ApplyDate(DateStruct Date, int Apply = 0)
{
	int DayCount = Date.Day += Apply;
	int YearCount = 0;

	while (true)
	{
		if (DayCount < 30)
		{
			break;
		}

		//Ȧ�������� ¦��������
		if (Date.Month & 1)
		{
			Date.Month += 1;
			DayCount -= 31;

		}

		else
		{
			Date.Month += 1;
			DayCount -= 30;
		}
	}

	while (Date.Month > 12)
	{
		Date.Month -= 12;
		YearCount++;
	}

	Date.Year += YearCount;
	Date.Day = DayCount;

	return Date;

}

int main(void)
{
	DateStruct CurrentDate;

	std::cout << "�� �� ��  : ";
	std::cin >> CurrentDate.Year >> CurrentDate.Month >> CurrentDate.Day;

	int ApplyDay;
	std::cout << "���� ���� : ";
	std::cin >> ApplyDay;

	DateStruct FutureDate = ApplyDate(CurrentDate, ApplyDay);

	std::cout << "�̷� ���� : " << FutureDate.Year << ' ' << FutureDate.Month << ' ' << FutureDate.Day<<'\n';
}