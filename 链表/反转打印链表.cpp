#include "SingleLinkList.h"
#include <iostream>
#include <stack>

void printListReversingly(const SingleLinkList &list)
{
	std::stack<int> stackData;
	listNode* p =list.getpHead();//使用常引用传参(const singleLinkList &list)，常对象list只能调用常函数，所以getpHead只能是const常函数
	while(p!=nullptr)
	{
		stackData.push(p->data);//栈中存节点指针更好，存数据会使占用空间增多
		p = p->next;
	}
	while (!stackData.empty())
	{
		std::cout<<stackData.top() << " ";
		stackData.pop();
	}
}