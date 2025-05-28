// 0528_NewDelete.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

struct Human
{
    int Age = 0;
    const char* Name = nullptr;
    //const char* PhoneNumber = nullptr;
};

#include <iostream>
#include <random>

int main()
{
    /*Human Man0 = {};
    Human* Man1 = new Human;
    Human* Mans = new Human[3];

    int Test = sizeof(Human);

    Human TestMan1;
    Human TestMan2;
    Human TestMan3;

    Man0.Age = 2;
    Man1->Age = 3;

    Man0.Name = "이주형";
    Man1->Name = "주형이";

    for (int i = 0; i < 3; i++)
    {
        Mans[i].Age = i+5;
        Mans[i].Name = "Temp Name";
        TestMan1 = Mans[i];
   }

    delete Man1;
    delete[] Mans;
    Man1 = nullptr;*/

    ////Step1
    //int* TestInt = new int;
    //std::cin >> *TestInt;

    //std::cout << *TestInt;
    //delete TestInt;
    //TestInt = nullptr;

    ////Step2
    //float* TestFloat = new float;
    //float* TestFloat2 = new float;
    //float* ResultFloat = new float;

    //std::cin >> *TestFloat >> *TestFloat2;
    //*ResultFloat = *TestFloat + *TestFloat2;

    //std::cout << *ResultFloat;

    //delete ResultFloat;
    //ResultFloat = nullptr;
    //delete TestFloat;
    //TestFloat = nullptr;
    //delete TestFloat2;
    //TestFloat2 = nullptr;

    //Step3
    /*int* RandomArray = new int[5];
    double* RandomAverage = new double;

    *RandomAverage = 0;

    std::random_device rd;

    for (int i = 0; i < 5; i++)
    {
        RandomArray[i] = (rd() % 100) + 1;
        std::cout << ' ' << RandomArray[i];
        *RandomAverage += RandomArray[i];
    }
    std::cout << '\n';
    std::cout << *RandomAverage / 5;

    delete[] RandomArray;
    delete RandomAverage;

    RandomArray = nullptr;
    RandomAverage = nullptr;*/

    //Step4

    int A = 10;
    int* TestPtr = &A;
    int* TestPtr2 = TestPtr;

    TestPtr++;
    *TestPtr = 11;

    int Temp = TestPtr2[1];


    int* NumOFNumber = new int;
    int* Min = new int;
    int* Max = new int;

    std::cout << "원하는 수 개수 : ";
    std::cin >> *NumOFNumber;
    std::cout << "\n\n";

    int* RandomNumberArray = new int[*NumOFNumber];

    *Min = 100;
    *Max = -1;

    for (int count = 0; count < *NumOFNumber; count++)
    {
        std::random_device rd;
        int RandomNumber = rd() % 100 + 1;
        RandomNumberArray[count] = RandomNumber;

        if (RandomNumber > *Max)
        {
            *Max = RandomNumber;
        }

        if (RandomNumber < *Min)
        {
            *Min = RandomNumber;
        }

        std::cout << ' ' << RandomNumber;
    }

    std::cout << '\n';
    std::cout << "Min : " << *Min << '\n';
    std::cout << "Max : " << *Max << '\n';


    delete NumOFNumber;
    delete Min;
    delete Max;

    NumOFNumber = nullptr;
    Min = nullptr;
    Max = nullptr;
}
