#pragma once
#include "������ڵ���.h"
class SingleLinkList               //��������
{
private:						//�������˽�б���Ϊ ��ģ��ͷָ��
	int size;
	listNode* pHead;
public:
	void initList();
	listNode* getpHead() const;
	void addToTail(int data);
	listNode* search(int data) const;
};

