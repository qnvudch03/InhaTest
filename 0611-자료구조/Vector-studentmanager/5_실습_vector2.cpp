#include <iostream>
#include <vector>
#include <list>
#include <map>
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
		std::cout << "�߰��� �л� �̸�: ";
		std::cin >> name;

		StudentArray.push_back(new Student(name));

		std::cout << name << " �л��� �߰��Ǿ����ϴ�.\n";
	}

	void RemoveStudentName()
	{
		std::cout << "=======================" << std::endl;
		std::string name;
		std::cout << "������ �л� �̸�: ";
		std::cin >> name;

		vector<Student*>::iterator it = StudentArray.begin();

		//int StudentCount = 0;
		bool bIsFind = false;



		//�׳� ������ ���
		/*{
			for (auto it : StudentArray)
			{
				if (!(it->_name.compare(name)))
				{
					std::cout << name << " �л��� �����Ǿ����ϴ�.\n";
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


		//���ͷ����� ���
		{
			vector<Student*>::iterator iter = StudentArray.begin();

			for (iter; iter != StudentArray.end();)
			{
				if (!(*iter)->_name.compare(name))
				{
					std::cout << name << " �л��� �����Ǿ����ϴ�.\n";
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

		if (!bIsFind)
		{
			std::cout << "�ش� �̸��� ã�� �� �����ϴ�.\n";
		}

	}

	void RemoveStudentByIndex()
	{
		std::cout << "=======================" << std::endl;
		int index;
		std::cout << "������ �л� �ε���: ";
		std::cin >> index;

		std::cout << StudentArray[index]->_name << " �л��� �����Ǿ����ϴ�.\n";

		delete StudentArray[index];
		StudentArray[index] = nullptr;

		StudentArray.erase(StudentArray.begin() + index);


	}

	void RemoveAllStudent()
	{
		std::cout << "=======================" << std::endl;

		int StudentIndexCount = 0;
		for (Student* CurrentStudent : StudentArray)
		{
			delete CurrentStudent;
			CurrentStudent = nullptr;

			StudentArray.erase(StudentArray.begin() + StudentIndexCount);
		}


		std::cout << "��� �л��� �����Ǿ����ϴ�.\n";
	}

	void SearchStudent()
	{
		std::cout << "=======================" << std::endl;
		std::string name;
		std::cout << "�˻��� �л� �̸�: ";
		std::cin >> name;

		int StudentCount = 0;
		bool bIsFind = false;
		for (auto it : StudentArray)
		{
			if (!(it->_name.compare(name)))
			{
				bIsFind = true;
				std::cout << "�ش� �л��� ���� �մϴ�.\n";
				return;
			}
		}

		std::cout << "�ش� �̸��� ã�� �� �����ϴ�.\n";


	}

	void PrintAll()
	{
		std::cout << "=======================" << std::endl;
		std::cout << "[���� �л� ���]" << std::endl;

		int Indexnum = 0;
		for (Student* CurrentStudent : StudentArray)
		{
			std::cout << "[ " << Indexnum << " ]" << "  " << CurrentStudent->_name << '\n';
			Indexnum++;
		}

	}

private:
	vector<Student*> StudentArray;
};

int main(void)
{
	StudentManager mgr;
	int choice;

	while (true)
	{
		std::cout << "\n=== �л� ��� ���� ===\n";
		std::cout << "1. �л� �߰�" << endl;
		std::cout << "2. �л� ����(�̸�)" << endl;
		std::cout << "3. �л� ����(�ε���)" << endl;
		std::cout << "4. �л� ��ü ����" << endl;
		std::cout << "5. �л� �˻�" << endl;
		std::cout << "6. ��ü ���" << endl;
		std::cout << "7. ȭ�� �����" << endl;
		std::cout << "8. ����" << endl;
		std::cout << "\n >>> ����: ";
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
		default: std::cout << "�߸��� �����Դϴ�.\n"; break;
		}
	}
}