#include "SingleLinkList.h"
#include <iostream>

void SingleLinkList::initList()
{
	pHead = nullptr;
	size = 0;
}
listNode* SingleLinkList::getpHead () const
{
	return pHead;
}
//void SingleLinkList::addToTail(SingleLinkList &list, int data)//
//{
//	listNode *pNew = new listNode();//为新节点开辟内存
//	pNew->data = data;
//	pNew->next = nullptr;
//
//	if (list.pHead == nullptr)//链表为空
//	{
//		list.pHead = pNew;
//	}
//	else                 //链表不为空
//	{
//		listNode *p = list.pHead;
//		while (p->next != nullptr)
//			p = p->next;
//		p->next = pNew;
//	}
//	size++;
//}
void SingleLinkList::addToTail(int data)//无需传入头指针或链表对象作参数
{
	listNode *pNew = new listNode();//为新节点开辟内存
	pNew->data = data;
	pNew->next = nullptr;

	if (pHead == nullptr)//链表为空
	{
		pHead = pNew;
	}
	else                 //链表不为空
	{
		listNode *p = pHead;
		while (p->next != nullptr)
			p = p->next;
		p->next = pNew;
	}
	size++;
}
listNode* SingleLinkList::search (int data) const
{
	if (pHead == nullptr)
		return NULL;
	listNode* p = pHead;
	while (p->data != data&&p->next != nullptr)
	{
		p = p->next;
	}
	if (p->data == data)
	{
		return p;
	}
	else if (p->next == nullptr)
	{
		return NULL;
	}
}