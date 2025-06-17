// 0613-Set.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <set>
#include <random>

#include <map>

using namespace std;

void makeRandomNum100(std::set<int>& mySet);
void ManageFriend(set<string>& mySet);

void AddFriend(set<string>& mySet);
void DeleteFriend(set<string>& mySet);
void FindFriend(set<string>& mySet);
void PrintFriend(set<string>& mySet);

int main()
{
    set<int> RandomNumberContainer;
    set<string> FriendManager;

    //행운의 숫자 777
    /*{
        makeRandomNum100(RandomNumberContainer);

        if (RandomNumberContainer.find(777) == RandomNumberContainer.end())
        {
            cout << "행운숫자 777이 없다!\n";
        }

        else
        {
            cout << "행운숫자 777이 있다!\n";
        }
    }*/

    ManageFriend(FriendManager);

    
}

void makeRandomNum100(std::set<int>& mySet)
{
    random_device rd;
    int RandomNumber = 0;
    while (true)
    {
        RandomNumber = (rd() % 1000) + 1;

        if (mySet.find(RandomNumber) == mySet.end())
            mySet.insert(RandomNumber);

        if (mySet.size() == 100)
            break;
    }
    return;
}

void ManageFriend(set<string>& mySet)
{
    int MyChoice = -1;

    map<int, std::string> myMap;
    myMap.find(1);

    while (true)
    {
        cout << "\n\n======================\n";
        cout << "1.친구 추가\n";
        cout << "2.친구 삭제\n";
        cout << "3.친구 검색\n";
        cout << "4.친구 목록\n";
        cout << "5.화면지우기\n";
        cout << "6.종료\n";

        cin >> MyChoice;



        switch (MyChoice)
        {
        case 1:
            //친구추가 함수
            AddFriend(mySet);
            break;
        case 2:
            //친구삭제 함수
            DeleteFriend(mySet);
            break;
        case 3:
            //친구검색 함수
            FindFriend(mySet);
            break;
        case 4:
            //친구출력 함수
            PrintFriend(mySet);
            break;
        case 6:
            //종료 함수
            return;
        case 5:
            system("cls");
            break;
        default:
            break;
        }
    }
    
}

void AddFriend(set<string>& mySet)
{
    string addedFriendName = "";
    cout << "======친구 추가======\n\n";
    cout << "추가할 친구 : ";
    cin >> addedFriendName;

    if (mySet.find(addedFriendName) == mySet.end())
    {
        mySet.insert(addedFriendName);
        cout << " '" << addedFriendName << "'" << " 친구목록에 추가 완료.\n";
    }

    else
    {
        cout << "이미 존재하는 친구 입니다.\n";
    }

}

void DeleteFriend(set<string>& mySet)
{
    string deletedFriendName = "";
    cout << "======친구 삭제======\n\n";
    cout << "삭제할 친구 : ";
    cin >> deletedFriendName;

    if (mySet.find(deletedFriendName) != mySet.end())
    {
        mySet.erase(deletedFriendName);
        cout << " '" << deletedFriendName << "'" << " 친구와 손절하였습니다.\n";
    }

    else
    {
        cout << "목록에 존재하지 않는 친구입니다.\n";
    }
}

void FindFriend(set<string>& mySet)
{
    string wantedFriendName = "";
    cout << "======친구 찾기======\n\n";
    cout << "찾을 친구 : ";
    cin >> wantedFriendName;

    if (mySet.find(wantedFriendName) != mySet.end())
    {
        int friendindex = 1;
        auto iter = mySet.begin();
        while (true)
        {
            if (iter == mySet.find(wantedFriendName))
                break;

            friendindex++;
            iter++;
        }
        cout << " '" << wantedFriendName << "'" << " 친구는 "<< friendindex << " 번째 목록에 저장되어 있습니다.\n";
    }

    else
    {
        cout << "목록에 존재하지 않는 친구입니다.\n";
    }
}

void PrintFriend(set<string>& mySet)
{
    cout << "======친구 목록======\n";
    auto iter = mySet.begin();
    int FriendCount = 1;
    while (true)
    {
        if (iter == mySet.end())
            break;

        std::cout << "[ " << FriendCount << " ]" << *iter << '\n';
        iter++;
        FriendCount++;
    }
}
