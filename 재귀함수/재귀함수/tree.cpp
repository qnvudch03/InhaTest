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

	//고조
	{
		rootNode->Child.push_back(new Node("고조 할아버지"));
		rootNode->Child.push_back(new Node("고조 할머니"));
	}

	//증조
	{
		for (auto Child : rootNode->Child)
		{
			Child->Child.push_back(new Node("증조 할아버지"));
			Child->Child.push_back(new Node("증조 할머니"));


			for (auto Child2 : Child->Child)
			{
				Child2->Child.push_back(new Node("할아버지"));
				Child2->Child.push_back(new Node("할머니"));


				for (auto Child3 : Child2->Child)
				{
					Child3->Child.push_back(new Node("아버지"));
					Child3->Child.push_back(new Node("어머니"));


					for (auto child4 : Child3->Child)
					{
						child4->Child.push_back(new Node("아들"));
						child4->Child.push_back(new Node("딸"));
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