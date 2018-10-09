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

/*
扩展：前序遍历的下一个结点
*/
template<typename T>
dtsBinaryTreeNode<T>* nextNode_pre(const dtsBinaryTreeNode<T>* pThis){
	if(pThis==NULL)
		return NULL;

	dtsBinaryTreeNode<T>* pNext=NULL;
	if(pThis->leftChild!=NULL){//有左子结点时，返回左子结点
		pNext=pThis->leftChild;
	} else if(pThis->rightChild!=NULL){
		pNext=pThis->rightChild;
	} else if(pThis->parent!=NULL){//没有子结点，但有父结点时，向上直到找到第一个是左子结点并且有右子结点的结点
		auto pParent=pThis;
		while(pParent->parent!=NULL &&
			!(pParent==pParent->parent->leftChild && pParent->parent->rightChild!=NULL)){
			pParent=pParent->parent;
		}
		if(pParent->parent!=NULL)
			pNext=pParent->parent->rightChild;
	}
	return pNext;
}


#define _TEST_IN(_tree,_val){\
	auto ret=nextNode_in(_tree.find_pre(_tree.getRoot(),_val));\
	if(ret){\
		cout<<_val<<" 的下一个结点是 "<<ret->value<<endl;\
	} else {\
		cout<<_val<<"没有下一个结点"<<endl;\
	}\
}


#define _TEST_PRE(_tree,_val){\
	auto ret=nextNode_pre(_tree.find_pre(_tree.getRoot(),_val));\
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
/*		0
	  1
	2
  3
4
*/
/* 0
	1
	 2
	  3
	   4
*/
int main(){
	dtsBinaryTree<int> tree(0),tree_right(0),tree_left(0);
	tree.add2Left_val(1,0).add2Right_val(2,0).add2Left_val(3,1).add2Right_val(4,1).add2Left_val(5,2).add2Right_val(6,2)
		.add2Left_val(7,3).add2Right_val(8,4);
	tree_left.add2Left_val(1,0).add2Left_val(2,1).add2Left_val(3,2).add2Left_val(4,3);
	tree_right.add2Right_val(1,0).add2Right_val(2,1).add2Right_val(3,2).add2Right_val(4,3);
	tree.print_in();//中序遍历
	_TEST_IN(tree,0);_TEST_IN(tree,1);_TEST_IN(tree,2);_TEST_IN(tree,3);_TEST_IN(tree,4);
	_TEST_IN(tree,5);_TEST_IN(tree,6);_TEST_IN(tree,7);_TEST_IN(tree,8);cout<<endl;
	tree_left.print_in();//中序遍历
	_TEST_IN(tree_left,0);_TEST_IN(tree_left,1);_TEST_IN(tree_left,2);_TEST_IN(tree_left,3);
	_TEST_IN(tree_left,4);cout<<endl;
	tree_right.print_in();//中序遍历
	_TEST_IN(tree_right,0);_TEST_IN(tree_right,1);_TEST_IN(tree_right,2);_TEST_IN(tree_right,3);
	_TEST_IN(tree_right,4);cout<<endl;
	tree.print_pre();
	_TEST_PRE(tree,0);_TEST_PRE(tree,1);_TEST_PRE(tree,2);_TEST_PRE(tree,3);_TEST_PRE(tree,4);
	_TEST_PRE(tree,5);_TEST_PRE(tree,6);_TEST_PRE(tree,7);_TEST_PRE(tree,8);cout<<endl;
	tree_left.print_pre();//中序遍历
	_TEST_PRE(tree_left,0);_TEST_PRE(tree_left,1);_TEST_PRE(tree_left,2);_TEST_PRE(tree_left,3);
	_TEST_PRE(tree_left,4);cout<<endl;
	tree_right.print_pre();//中序遍历
	_TEST_PRE(tree_right,0);_TEST_PRE(tree_right,1);_TEST_PRE(tree_right,2);_TEST_PRE(tree_right,3);
	_TEST_PRE(tree_right,4);cout<<endl;


	dtsBinaryTreeNode<int>* nullTreeRoot=NULL;
	dtsBinaryTree<int> nullTree(nullTreeRoot);
	_TEST_IN(nullTree,0);

	return 0;
}
