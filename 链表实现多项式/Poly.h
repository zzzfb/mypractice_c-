#pragma once
struct PolyNode
{
	int index;//指数
	int coeff;//系数
	PolyNode *next;
};
class Poly
{
private:
	int m_high;//最高项指数
	PolyNode *m_first;
public:
	Poly();
	Poly(int high, int *coeffArray);
	PolyNode* getFirst() const;
	void show() const;
	void add(const Poly &poly1, const Poly &poly2, Poly &poly);
};