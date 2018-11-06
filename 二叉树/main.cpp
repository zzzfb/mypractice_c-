#include "binTree.h"
#include "BST.h"
int main()
{
	BST<int> bt(6);
	bt.insertAsLC(bt.root(), 2);
	bt.insertAsRC(bt.root(), 10);
	bt.insertAsLC(bt.root()->lchild, 0);
	bt.insertAsRC(bt.root()->lchild, 4);
	bt.insertAsLC(bt.root()->rchild, 8);
	bt.insertAsRC(bt.root()->rchild, 12);

	cout << "前序遍历：" << endl;
	bt.travPre_ite2(bt.root());
	cout << endl << "中序遍历：" << endl;
	bt.travMid_ite(bt.root());

	//binNode<int>* x = bt.search(8);
	//cout <<endl<< bt.hot()->data<<endl;

	binNode<int>* y=bt.insert(9);
	//cout << y->data << endl;

	cout <<endl<< "前序遍历：" << endl;
	bt.travPre_ite2(bt.root());
	cout << endl << "中序遍历：" << endl;
	bt.travMid_ite(bt.root());
	return 0;
}