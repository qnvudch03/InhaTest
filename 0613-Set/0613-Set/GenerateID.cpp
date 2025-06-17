#include <iostream>

#include <map>
#include <random>
#include <vector>

#define Chance 10

class MyStat
{
public:
	MyStat()
	{
		std::random_device rd;

		_Atk = (rd() % 100);
		_Def = (rd() % 100);
		_Id = GenerateID();
	}
	~MyStat() {}

	int GenerateID()
	{
		static int ID = 0;
		ID++;

		return ID;
	}

	int GetAtk() { return _Atk; }
	int GetDef() { return _Def; }
	int GetId() { return _Id; }

private:
	int _Atk;
	int _Def;
	int _Id;
};

struct MyStruct
{
	int _Atk = 0;
	int _Def = 0;
};

void GetRandomReword(std::map<int, MyStat*>& myMap, std::vector<bool>& AccessArray);


int main(void)
{
	std::map<int, MyStat*> CollectorReword;
	std::vector<bool> AccessArray(100, true);

	MyStruct Player;

	GetRandomReword(CollectorReword, AccessArray);

	for (auto Reword : CollectorReword)
	{
		std::cout << "도전과제 [ " << Reword.first << " ] 보상\n";
		std::cout << "ATK : +" << Reword.second->GetAtk()<<"\n";
		std::cout << "DEF : +" << Reword.second->GetDef()<<"\n";

		Player._Atk += Reword.second->GetAtk();
		Player._Def += Reword.second->GetDef();

		delete Reword.second;
		Reword.second = nullptr;
	}

	std::cout << "\n\n======최종 스탯=====\n";
	std::cout << "Atk : " << Player._Atk<<'\n';
	std::cout << "DEF : " << Player._Def;

	CollectorReword.clear();
	return 0;
}

void GetRandomReword(std::map<int, MyStat*>& myMap, std::vector<bool>& AccessArray)
{
	std::random_device rd;

	for (int i = 0; i < Chance; i++)
	{
		int randomIndex = (rd() % 100);

		if (AccessArray[randomIndex] != true)
		{
			std::cout << "[ " << randomIndex << " ] 이미 달성한 도전과제 입니다.\n";
			continue;
		}
	
		myMap[randomIndex] = new MyStat();
		AccessArray[randomIndex] = false;

		//if (myMap.find(randomIndex) == myMap.end())
		//{

		//}

	}
}