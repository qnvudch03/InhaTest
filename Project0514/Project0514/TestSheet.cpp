#include <iostream>
#include <random>

void FushArray(int* Array, int Count = 0);

int main(void)
{
	int RandomTestArray[5] = {};

	for (int & ArrayNum : RandomTestArray)
	{
		std::random_device rd;
		ArrayNum = (rd() % 100);
	}

	//���� ����ϱ�

	/*for (int i = sizeof(RandomTestArray) / sizeof(int); i > 0; i--)
	{
		std::cout << RandomTestArray[i -1] << ' ';
	}*/

	//��� �� ���ϱ�

	/*int Sum = 0;
	for (int& ArrayNum : RandomTestArray)
	{
		Sum += ArrayNum;
	}

	std::cout << "��� �� : " << (double)Sum / (sizeof(RandomTestArray) / sizeof(int));*/

	//�ּ� �ִ� ���ϱ�

	int RangeIndex[5] = {-1, -1, -1, -1, -1};

	for (int i = 0; i < sizeof(RandomTestArray) / sizeof(int); i++)
	{
		int biggestIndex = 0;
		for (int& TempNum : RangeIndex)
		{
			if (RandomTestArray[i] > TempNum)
			{
				FushArray(RangeIndex, biggestIndex);
				/*{
					if (RangeIndex[biggestIndex + 1] != -1)
					{
						RangeIndex[biggestIndex + 2] = RangeIndex[biggestIndex + 1];
					}
					RangeIndex[biggestIndex + 1] = RangeIndex[biggestIndex];
				}*/
				RangeIndex[biggestIndex] = RandomTestArray[i];
				break;
			}
			biggestIndex++;
		}
	}
}

void FushArray(int* Array, int Count)
{
	if (Array[Count] == -1)
		return;

	int Temp = Array[Count];
	Array[Count + 1] = Array[Count];
	Count++;
	FushArray(Array, Count);
}
