#pragma once
#include <stack>
#include <iostream>
using namespace std;

template <typename T>
struct binNode
{
	T data;
	binNode<T>* parent;
	binNode<T>* lchild;
	binNode<T>* rchild;
	binNode(const T& e) { data = e; parent = nullptr; lchild = nullptr; rchild = nullptr; }
	binNode(const T& e, binNode<T>* x) { data = e; parent = x; lchild = nullptr; rchild = nullptr;}
	binNode<T>* insertAsLC(const T& e) { return lchild = new binNode<T>(e, this); }
	binNode<T>* insertAsRC(const T& e) { return rchild = new binNode<T>(e, this); }
};
template <typename T>
class binTree
{
protected:
	int _size;
	binNode<T>* _root;
	void visitAlongLeftBranch(binNode<T>* x,stack<binNode<T>* > &S);
	void goAlongLeftBranch(binNode<T>* x, stack<binNode<T>* > &S);
public:
	binTree() { _root = nullptr; _size = 0; }
	binTree(const T& e) { _root = new binNode<T>(e);  _size = 1; }
	bool empty() const { return _root == nullptr; }
	binNode<T>* root() const { return _root; }
	T& visit(binNode<T>* x) const  
	{
		cout << x->data<<" ";
		return x->data; 
	}
	binNode<T>* insertAsLC(binNode<T>* x, const T& e);
	binNode<T>* insertAsRC(binNode<T>* x, const T& e);
	void travPre_rec(binNode<T>* x);
	void travPre_ite2(binNode<T>* x);
	void travMid_ite(binNode<T>* x);
};

template <typename T>//插入节点作为左孩子
binNode<T>* binTree<T>::insertAsLC(binNode<T>* x, const T& e)
{
	_size++;
	x->insertAsLC(e);
	return x->lchild;
}
template <typename T>//插入节点作为右孩子
binNode<T>* binTree<T>::insertAsRC(binNode<T>* x, const T& e)
{
	_size++;
	x->insertAsRC(e);
	return x->rchild;
}
template <typename T>//前序遍历，递归实现
void binTree<T>::travPre_rec(binNode<T>* x)
{
	if (!x)
		return;
	visit(x);
	travPre(x->lchild);
	travPre(x->rchild);
}
template <typename T>//遍历左侧链
void binTree<T>::visitAlongLeftBranch(binNode<T>* x, stack<binNode<T>* > &S)
{
	while (x)
	{
		visit(x);
		S.push(x->rchild);
		x = x->lchild;
	}
}
template <typename T>//前序遍历，改进的迭代实现
void binTree<T>::travPre_ite2(binNode<T>* x)
{
	stack<binNode<T>* > S;
	while (true)
	{
		visitAlongLeftBranch(x, S);
		if (S.empty())
		{
			break;
		}
		x = S.top();
		S.pop();
	}
}
template<typename T>//游历左侧链
void binTree<T>::goAlongLeftBranch(binNode<T>* x, stack<binNode<T>* > &S)
{
	while (x)
	{
		S.push(x);
		x = x->lchild;
	}
}
template <typename T>//中序遍历，迭代实现
void binTree<T>::travMid_ite(binNode<T>* x)
{
	stack<binNode<T>* > S;
	while (true)
	{
		goAlongLeftBranch(x, S);
		if (S.empty())
			break;
		x = S.top();
		S.pop();
		visit(x);
		x = x->rchild;
	}
}
