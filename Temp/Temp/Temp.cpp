#include <iostream>
#include <vector>

//template<typename T, typename Y>
//T GetMax(T First, Y Second);
//
//template<typename T, typename Y>
//T GetMax(T First, Y Second)
//{
//	return (First > Second) ? First : Second;
//}

template<typename T>
class MyStackClass
{
public:
	MyStackClass() {}
	~MyStackClass() {}

	//push top
	void push(const T InputValue)
	{
		DataVector.push_back(InputValue);
	}

	//delete top data
	void pop()
	{
		if(DataVector.size() != 0)
			DataVector.pop_back();
	}

	//return top data
	T top()
	{
		if (DataVector.size() != 0)
		{
			return DataVector[DataVector.size() - 1];
		}

		else

			return 0;

	}

	bool isEmpty()
	{
		return DataVector.empty();
	}

private:
	std::vector<T> DataVector;
};

int main(void)
{
	//int TestNumber = 520;
	////std::string TestString = "What";
	////int TestNumber2 = 520.7;

	//int Result = GetMax(TestNumber, 520.7);

	MyStackClass<int> MyStack;


	MyStack.push(5);
	MyStack.push(4);
	MyStack.push(3);
	MyStack.push(2);
	MyStack.push(1);

	auto IsEmpty = MyStack.isEmpty();

	MyStack.pop();

	auto TopValue = MyStack.top();



}


