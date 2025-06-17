#include <iostream>
#include <list>

using namespace std;

class Student
{
public:
	Student() {}
	Student(const string& name) : _name(name) {}

	string _name;

};

class StudentManager
{
public:
	void AddStudent()
	{
		std::cout << "=======================" << std::endl;
		std::string name;
		std::cout << "추가할 학생 이름: ";
		std::cin >> name;

		StudentArray.push_back(new Student(name));

		std::cout << name << " 학생이 추가되었습니다.\n";
	}

	void RemoveStudentName()
	{
		std::cout << "=======================" << std::endl;
		std::string name;
		std::cout << "삭제할 학생 이름: ";
		std::cin >> name;

		list<Student*>::iterator it = StudentArray.begin();

		//int StudentCount = 0;
		bool bIsFind = false;



		//그냥 포인터 방식
		/*{
			for (auto it : StudentArray)
			{
				if (!(it->_name.compare(name)))
				{
					std::cout << name << " 학생이 삭제되었습니다.\n";
					bIsFind = true;

					delete StudentArray[StudentCount];
					StudentArray[StudentCount] = nullptr;

					StudentArray.erase(StudentArray.begin() + StudentCount);
				}
				else
				{
					StudentCount++;
				}
			}

		}*/


		//이터레이터 방식
		{
			list<Student*>::iterator iter = StudentArray.begin();

			for (iter; iter != StudentArray.end();)
			{
				if (!(*iter)->_name.compare(name))
				{
					std::cout << name << " 학생이 삭제되었습니다.\n";
					bIsFind = true;

					delete (*iter);
					(*iter) = nullptr;

					iter = StudentArray.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}


		//StudentArray.remove();

		if (!bIsFind)
		{
			std::cout << "해당 이름을 찾을 수 없습니다.\n";
		}

	}

	void RemoveStudentByIndex()
	{
		std::cout << "=======================" << std::endl;
		int index;
		std::cout << "삭제할 학생 인덱스: ";
		std::cin >> index;

		auto iter = StudentArray.begin();

		for (int count = 0; count < index; count++)
		{
			iter++;
		}

		std::cout << (*iter)->_name << " 학생이 삭제되었습니다.\n";

		delete* iter;
		*iter = nullptr;

		StudentArray.erase(iter);

	}

	void RemoveAllStudent()
	{
		std::cout << "=======================" << std::endl;

		/*int StudentIndexCount = 0;
		for (Student* CurrentStudent : StudentArray)
		{
			delete CurrentStudent;
			CurrentStudent = nullptr;

			StudentArray.erase(StudentArray.begin() + StudentIndexCount);
		}*/

		//1번 방법
		//StudentArray.clear();


		//2번 방법

		auto iter = StudentArray.begin();

		for (iter; iter != StudentArray.end();)
		{
			delete *iter;
			*iter = nullptr;
			iter = StudentArray.erase(iter);
		}


		std::cout << "모든 학생이 삭제되었습니다.\n";
	}

	void SearchStudent()
	{
		std::cout << "=======================" << std::endl;
		std::string name;
		std::cout << "검색할 학생 이름: ";
		std::cin >> name;

		int StudentCount = 0;
		bool bIsFind = false;
		for (auto it : StudentArray)
		{
			if (!(it->_name.compare(name)))
			{
				bIsFind = true;
				std::cout << "해당 학생이 존재 합니다.\n";
				return;
			}
		}

		std::cout << "해당 이름을 찾을 수 없습니다.\n";


	}

	void PrintAll()
	{
		std::cout << "=======================" << std::endl;
		std::cout << "[현재 학생 명단]" << std::endl;

		int Indexnum = 0;
		for (Student* CurrentStudent : StudentArray)
		{
			std::cout << "[ " << Indexnum << " ]" << "  " << CurrentStudent->_name << '\n';
			Indexnum++;
		}

	}

private:
	list<Student*> StudentArray;
};

int main()
{
	StudentManager mgr;
	int choice;

	while (true)
	{
		std::cout << "\n=== 학생 명단 관리 ===\n";
		std::cout << "1. 학생 추가" << endl;
		std::cout << "2. 학생 삭제(이름)" << endl;
		std::cout << "3. 학생 삭제(인덱스)" << endl;
		std::cout << "4. 학생 전체 삭제" << endl;
		std::cout << "5. 학생 검색" << endl;
		std::cout << "6. 전체 출력" << endl;
		std::cout << "7. 화면 지우기" << endl;
		std::cout << "8. 종료" << endl;
		std::cout << "\n >>> 선택: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1: mgr.AddStudent(); break;
		case 2: mgr.RemoveStudentName(); break;
		case 3: mgr.RemoveStudentByIndex(); break;
		case 4: mgr.RemoveAllStudent(); break;
		case 5: mgr.SearchStudent(); break;
		case 6: mgr.PrintAll(); break;
		case 7: system("cls"); break;
		case 8: return 0;
		default: std::cout << "잘못된 선택입니다.\n"; break;
		}
	}
}