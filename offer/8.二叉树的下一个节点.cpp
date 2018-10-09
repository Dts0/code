#include<iostream>
#include"../myTemplates/dtsBinaryTree.hpp"

using namespace std;

/*
给出二叉树，找出中序遍历的下一个结点
*/
template<typename T>
dtsBinaryTreeNode<T>* nextNode_in(const dtsBinaryTreeNode<T>* pThis){
	if(pThis==NULL)
		return NULL;

	dtsBinaryTreeNode<T>* pNext=NULL;
	if(pThis->rightChild!=NULL){//有右子结点时，返回右子结点的最左下结点
		auto pRight=pThis->rightChild;
		while(pRight->leftChild!=NULL){
			pRight=pRight->leftChild;
		}
		pNext=pRight;
	} else if(pThis->parent!=NULL){//没有右子结点且父结点不为空时，向上直到为左子结点
		auto pCurrent=pThis;
		auto pParent=pThis->parent;
		while(pParent!=NULL && pCurrent==pParent->rightChild){//是父结点的右子结点时,向上一层
			pCurrent=pParent;
			pParent=pParent->parent;
		}
		pNext=pParent;
	}
	return pNext;
}

#define _TEST(_tree,_val){\
	auto ret=nextNode_in(_tree.find_pre(_tree.getRoot(),_val));\
	if(ret){\
		cout<<_val<<" 的下一个结点是 "<<ret->value<<endl;\
	} else {\
		cout<<_val<<"没有下一个结点"<<endl;\
	}\
}

/*
         0
	1        2
  3  4     5  6
7     8
*/
int main(){
	dtsBinaryTree<int> tree(0);
	tree.add2Left_val(1,0).add2Right_val(2,0).add2Left_val(3,1).add2Right_val(4,1).add2Left_val(5,2).add2Right_val(6,2)
		.add2Left_val(7,3).add2Right_val(8,4);
	tree.print_in();//中序遍历
	_TEST(tree,1);
	_TEST(tree,2);
	_TEST(tree,3);
	_TEST(tree,4);
	_TEST(tree,5);
	_TEST(tree,6);
	_TEST(tree,7);
	_TEST(tree,8);

	dtsBinaryTreeNode<int>* nullTreeRoot=NULL;
	dtsBinaryTree<int> nullTree(nullTreeRoot);
	_TEST(nullTree,0);

	return 0;
}
