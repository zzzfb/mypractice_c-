#include "SingleLinkList.h"
#include <iostream>
#include <stack>

void printListReversingly(const SingleLinkList &list)
{
	std::stack<int> stackData;
	listNode* p =list.getpHead();//ʹ�ó����ô���(const singleLinkList &list)��������listֻ�ܵ��ó�����������getpHeadֻ����const������
	while(p!=nullptr)
	{
		stackData.push(p->data);//ջ�д�ڵ�ָ����ã������ݻ�ʹռ�ÿռ�����
		p = p->next;
	}
	while (!stackData.empty())
	{
		std::cout<<stackData.top() << " ";
		stackData.pop();
	}
}