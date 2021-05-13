#include <cstdlib>
#include <ctime>
#include"BiNode.h"
#include"Node.h"
#include"SList.h"
#include"Stack.h"
#include"Queue.h"
#include"BinaryTree.h"

int main() {

	srand((int)time(0));

	//SLIST
	{
		SList<int> list1();
		SList<int> list2(10);




	}

	//Queue
	{
		Queue<int> queue1(10);
		Queue<int> queue2(10);
		std::cout << queue1 << std::endl;
		std::cout << queue2 << std::endl;
		queue1.pop();
		queue1.push(100);
		std::cout << queue1 << std::endl;
		queue1.isEmpty();
		queue1.find(100);
		queue1.size();
		queue1.link(queue2);
		std::cout << queue1 << std::endl;
		queue1.clear();
		queue1.isEmpty();
		std::cout << queue1 << std::endl;
	}
	
	//BinaryTree
	{
		BinaryTree<int> binarytree;
		for (int i = 0; i < 10; i++) {
			binarytree.insert(rand() % 100);
		}
		binarytree.inOrder(binarytree.root(), visit);
		std::cout << std::endl;
		BinaryTree<int> binarytree1(5);
		binarytree1.inOrder(binarytree1.root(), visit);
		std::cout << std::endl;
	}


	return 0;
}