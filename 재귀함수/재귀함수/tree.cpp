#include <iostream>
#include <vector>

class Node
{
public:
	Node(const std::string& name) : Name(name) {};
	std::vector<Node*> Child;
	std::string Name;
};

Node* MakeTree()
{
	Node* rootNode = new Node("The One");

	//����
	{
		rootNode->Child.push_back(new Node("���� �Ҿƹ���"));
		rootNode->Child.push_back(new Node("���� �ҸӴ�"));
	}

	//����
	{
		for (auto Child : rootNode->Child)
		{
			Child->Child.push_back(new Node("���� �Ҿƹ���"));
			Child->Child.push_back(new Node("���� �ҸӴ�"));


			for (auto Child2 : Child->Child)
			{
				Child2->Child.push_back(new Node("�Ҿƹ���"));
				Child2->Child.push_back(new Node("�ҸӴ�"));


				for (auto Child3 : Child2->Child)
				{
					Child3->Child.push_back(new Node("�ƹ���"));
					Child3->Child.push_back(new Node("��Ӵ�"));


					for (auto child4 : Child3->Child)
					{
						child4->Child.push_back(new Node("�Ƶ�"));
						child4->Child.push_back(new Node("��"));
					}
				}

			}

		}
	}

	return rootNode;

}

void PrintTree(Node* InNode, int level = 0)
{
	Node* CurrentNode = InNode;

	for (int i = 0; i < level; i++)
	{
		std::cout << '-';
	}
	std::cout << CurrentNode->Name<<'\n';

	for (auto ChildNode : CurrentNode->Child)
	{
		PrintTree(ChildNode, level+1);
	}
}

int main(void)
{
	Node* node = MakeTree();
	PrintTree(node);
	return 0;
}