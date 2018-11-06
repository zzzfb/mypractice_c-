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
//	listNode *pNew = new listNode();//Ϊ�½ڵ㿪���ڴ�
//	pNew->data = data;
//	pNew->next = nullptr;
//
//	if (list.pHead == nullptr)//����Ϊ��
//	{
//		list.pHead = pNew;
//	}
//	else                 //����Ϊ��
//	{
//		listNode *p = list.pHead;
//		while (p->next != nullptr)
//			p = p->next;
//		p->next = pNew;
//	}
//	size++;
//}
void SingleLinkList::addToTail(int data)//���贫��ͷָ����������������
{
	listNode *pNew = new listNode();//Ϊ�½ڵ㿪���ڴ�
	pNew->data = data;
	pNew->next = nullptr;

	if (pHead == nullptr)//����Ϊ��
	{
		pHead = pNew;
	}
	else                 //����Ϊ��
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