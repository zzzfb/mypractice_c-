#pragma once
#include "BST.h"
template<typename T>
class AVL :public BST<T>
{
public:
	using BST::BST;
	binNode<T>* insert(const T & e);

};
template <typename T>
binNode<T>* AVL<T>::insert(const T & e)
{
	
}