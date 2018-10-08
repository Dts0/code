#include"dtsBinaryTree.hpp"
#include<iostream>
using namespace std;

/*
         0
	1        2
  3  4     5  6
7     8

*/
int main(){
//可以自己创建，然后将跟结点给构造函数
	dtsBinaryTreeNode<int>* root=new dtsBinaryTreeNode<int>(0);
	dtsBinaryTreeNode<int>* node1=new dtsBinaryTreeNode<int>(1);
	dtsBinaryTreeNode<int>* node2=new dtsBinaryTreeNode<int>(2);
	dtsBinaryTreeNode<int>* node3=new dtsBinaryTreeNode<int>(3);
	dtsBinaryTreeNode<int>* node4=new dtsBinaryTreeNode<int>(4);
	dtsBinaryTreeNode<int>* node5=new dtsBinaryTreeNode<int>(5);
	dtsBinaryTreeNode<int>* node6=new dtsBinaryTreeNode<int>(6);
	dtsBinaryTreeNode<int>* node7=new dtsBinaryTreeNode<int>(7);
	dtsBinaryTreeNode<int>* node8=new dtsBinaryTreeNode<int>(8);

	root->leftChild=node1;
	root->rightChild=node2;
	node1->leftChild=node3;
	node1->rightChild=node4;
	node3->leftChild=node7;
	node4->rightChild=node8;
	node2->leftChild=node5;
	node2->rightChild=node6;


	dtsBinaryTree<int> tree0(root);
	tree0.print_pre();//前序遍历
	tree0.print_in();//中序遍历
	tree0.print_post();//后序遍历
	cout<<endl;

/*
         0
	1        2
  3  4     5  6
7     8

*/
	//也可以把根结点值给构造函数，来创建一个二叉树
	dtsBinaryTree<int> tree(0);
	tree.add2Left_val(1,0).add2Right_val(2,0).add2Left_val(3,1).add2Right_val(4,1).add2Left_val(5,2).add2Right_val(6,2)
		.add2Left_val(7,3).add2Right_val(8,4);
	tree.print_pre();//前序遍历
	tree.print_in();//中序遍历
	tree.print_post();//后序遍历

	//测试parent
	cout<<tree.find_pre(tree.getRoot(),3)->parent->parent->value<<endl;
	cout<<tree.find_pre(tree.getRoot(),4)->parent->value<<endl;
	return 0;
}
