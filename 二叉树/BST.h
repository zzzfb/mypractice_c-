#pragma once
#include "binTree.h"
template<typename T>
class BST :public binTree<T>
{
protected:
	binNode<T>* _hot;
public:
	using binTree<T>::binTree;
	binNode<T>* hot() const { return _hot; }
	virtual binNode<T>* & search(const T & e);
	virtual binNode<T>*  insert(const T & e);
	binNode<T>* & search_rev(const T & e);
	binNode<T>* & inSearch(binNode<T>* & x, const T &e, binNode<T>* & hot);
};

template<typename T>//��������
binNode<T>* & BST<T>::search(const T & e)
{
	binNode<T>* &x = _root;//�����ÿ�ֱ�Ӷ��������޸ģ��Ա㷵�ص����ü�_hot->lchild��rchild���Դ���insert�п�ֱ�Ӹ�ֵ
	while (x)             //���޸��˸�ָ��
	{
		if (x->data == e)
			return x;
		else if (x->data < e)
		{
			_hot = x;
			x = x->rchild;
		}
		else
		{
			_hot = x;
			x = x->lchild;
		}
	}
	return x;
}
template<typename T>//�ݹ����
binNode<T>* & BST<T>::search_rev(const T & e)
{
	return inSearch(_root, e, _hot);
}
template<typename T>
binNode<T>* & BST<T>::inSearch(binNode<T>* & x, const T &e, binNode<T>* & _hot)
{
	if (!x || x->data == e)
		return x;
	_hot = x;
	return inSearch(x->data < e ? x->rchild : x->lchild, e, _hot);
}
template<typename T>//����
binNode<T>*  BST<T>::insert(const T & e)
{
	binNode<T>* & x = search_rev(e);
	if (!x)
	{
		x = new binNode<T>(e, _hot);
		_size++;
	}
	return x;
}