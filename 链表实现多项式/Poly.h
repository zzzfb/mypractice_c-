#pragma once
struct PolyNode
{
	int index;//ָ��
	int coeff;//ϵ��
	PolyNode *next;
};
class Poly
{
private:
	int m_high;//�����ָ��
	PolyNode *m_first;
public:
	Poly();
	Poly(int high, int *coeffArray);
	PolyNode* getFirst() const;
	void show() const;
	void add(const Poly &poly1, const Poly &poly2, Poly &poly);
};