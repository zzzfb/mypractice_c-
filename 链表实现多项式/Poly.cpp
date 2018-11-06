#include "Poly.h"
#include <iostream>
Poly::Poly()
{
	m_first = nullptr;
}
Poly::Poly(int high, int *coeffArray)//应对传入的high和数组进行检查,第一个参数为最高项指数，数组元素个数应为high+1
{
	m_high = high;
	m_first = new PolyNode();
	PolyNode *p = m_first;
	for (int i = 0; i < high ; i++)//若为high+1，最后会多申请一个内存空间，里面值默认为0
	{
		p->index = i;
		p->coeff = coeffArray[i];
		p->next = new PolyNode();
		p = p->next;
	}
	p->index = high;
	p->coeff = coeffArray[high];
}
PolyNode* Poly::getFirst() const
{
	return m_first;
}
void Poly::show() const
{
	if (m_first != nullptr)
	{
		PolyNode *p = m_first;
		std::cout << p->coeff;//指数为0的项不显示x^0部分
		p = p->next;
		while (p != nullptr)
		{
			if (p->coeff != 0)//系数为0的项不显示
			{
				std::cout << "+" << p->coeff << "x^" << p->index;
			}
			p = p->next;
		}
		std::cout << std::endl;
	}
}
void Poly::add(const Poly &poly1, const Poly &poly2, Poly &poly)
{
	PolyNode *p1 = poly1.getFirst();
	PolyNode *p2 = poly2.getFirst();
	PolyNode *p = poly.getFirst();
	while (p1 != nullptr && p2 != nullptr)
	{
		p->index = p1->index;
		p->coeff = p1->coeff + p2->coeff;
		p1 = p1->next;
		p2 = p2->next;
		p = p->next;
	}
	if (p1 == nullptr)
	{
		while (p2 != nullptr)
		{
			p->index = p2->index;
			p->coeff = p2->coeff;
			p2 = p2->next;
			p = p->next;
		}
	}
	else
	{
		while (p1 != nullptr)
		{
			p->index = p1->index;
			p->coeff = p1->coeff;
			p1 = p1->next;
			p = p->next;
		}
	}
}