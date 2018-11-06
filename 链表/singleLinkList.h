#pragma once
#include "单链表节点类.h"
class SingleLinkList               //单向链表
{
private:						//链表类的私有变量为 规模和头指针
	int size;
	listNode* pHead;
public:
	void initList();
	listNode* getpHead() const;
	void addToTail(int data);
	listNode* search(int data) const;
};

