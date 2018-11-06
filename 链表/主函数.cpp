#include "SingleLinkList.h"
#include <iostream>
using namespace std;
int main()
{
	SingleLinkList list;
	list.initList();
	list.addToTail(5);
	//list.addToTail(6);
	//list.addToTail(8);
	//listNode* p=list.search(3);
	//cout << p->next->data;
	void printListReversingly(const SingleLinkList &list);
	printListReversingly(list);
	return 0;
}