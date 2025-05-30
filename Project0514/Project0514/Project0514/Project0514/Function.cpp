#include <iostream>
#include <Windows.h>
#include <vector>

int MakeBread(int Material)
{
	return 0;
}

void GetRandomItem()
{

}

int main(void)
{
	std::string SSR_Item[] = { "(SSR)Gold Sword" , "(SSR)Fire Blade", "(SSR)Eterner Hear", "(SSR)Frost King's Ring", "(SSR)Sun Blad", "(SSR)Moon Silde"};
	std::string S_Item[] = { "(S)Assesin's hood", "(S)Sliver Sword", "(S)Crow's Eye", "(S)Mountain Shouse" };
	std::string N_Item[] = { "(N)Coin", "(N)Garbage", "(N)Root Crown", "(N)Clean shirts", "(N)boots", "(N)baverage", "(N)rarishe", "(N)GameCard" };

	float SSR_Rate = 0.02f;
	float S_Rate = 0.15f;
	float N_Rate = 0.83;

	std::vector<std::string> GaChaResult;

	while (true)
	{
		int GaChaNum = 0;
		std::cout << "---------·£´ý»Ì±â °¡Ã­---------\n\n";
		std::cout << "»Ì±â °³¼ö : ";
		std::cin >> GaChaNum;


		for (int i = 0; i < GaChaNum; i++)
		{
			srand(time(0));
			float Rare = 1.f / (rand() % 100 + 1);

			if (Rare < SSR_Rate)
			{
				int RandomIndex = (rand() % (sizeof(SSR_Item) / sizeof(std::string)));
				GaChaResult.push_back(SSR_Item[RandomIndex]);
			}

			else if (Rare < S_Rate)
			{
				int RandomIndex = (rand() % (sizeof(S_Item) / sizeof(std::string)));
				GaChaResult.push_back(S_Item[RandomIndex]);
			}

			else
			{
				int RandomIndex = (rand() % (sizeof(N_Item) / sizeof(std::string)));
				GaChaResult.push_back(N_Item[RandomIndex]);
			}

			int tempNum = 0;
			std::cin >> tempNum;

		}



		std::cout << "\n\n";
		std::cout << "°¡Ã­ °á°ú [ ";
		for (int i = 0; i < GaChaNum; i++)
		{
			std::cout << GaChaResult[i] << "  ";
		}

		std::cout << " ] ";

		int bIsReRoll = 0;
		std::cout << "\n\n RE?    <Yes : 1>   <No : 0>";
		std::cin >> bIsReRoll;

		if (bIsReRoll == 1)
		{
			std::cout << "\n\n\n";
			GaChaResult.clear();
			continue;
		}


		else if (bIsReRoll == 0);
		break;

	}
}