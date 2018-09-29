#ifndef DTS_BINARY_TREE_HPP
#define DTS_BINARY_TREE_HPP

#include<iostream>
#include<functional>

using namespace std;

template <typename T>
class dtsBinaryTreeNode{
public:
	T value;
	dtsBinaryTreeNode<T>* leftChild;
	dtsBinaryTreeNode<T>* rightChild;
	dtsBinaryTreeNode(T val,dtsBinaryTreeNode<T>* left=NULL,dtsBinaryTreeNode<T>* right=NULL)
				:value(val),leftChild(left),rightChild(right){}
	dtsBinaryTreeNode(){}
};

//后序遍历并执行函数func

template <typename T>
class dtsBinaryTree{
	dtsBinaryTreeNode<T>* root;
	//前序遍历
	static void doSomethingTree_preOrder(dtsBinaryTreeNode<T>* root,function<void(dtsBinaryTreeNode<T>* node)> func){
	if(!root)
		return;
	func(root);
	dtsBinaryTree::doSomethingTree_preOrder(root->leftChild,func);
	dtsBinaryTree::doSomethingTree_preOrder(root->rightChild,func);
	}
	//中序遍历
	static void doSomethingTree_inOrder(dtsBinaryTreeNode<T>* root,function<void(dtsBinaryTreeNode<T>* node)> func){
	if(!root)
		return;
	dtsBinaryTree::doSomethingTree_inOrder(root->leftChild,func);
	func(root);
	dtsBinaryTree::doSomethingTree_inOrder(root->rightChild,func);
	}
	//后序遍历
	static void doSomethingTree_postOrder(dtsBinaryTreeNode<T>* root,function<void(dtsBinaryTreeNode<T>* node)> func){
	if(!root)
		return;
	dtsBinaryTree::doSomethingTree_postOrder(root->leftChild,func);
	dtsBinaryTree::doSomethingTree_postOrder(root->rightChild,func);
	func(root);
	}

public:
	dtsBinaryTree(T rootValue){
		root=new dtsBinaryTreeNode<T>(rootValue);
	}
	dtsBinaryTree(dtsBinaryTreeNode<T>* rt):root(rt){}

	static dtsBinaryTreeNode<T>* find_pre(dtsBinaryTreeNode<T>* root,T val,int n=1,int* cnt=NULL){//返回前序遍历找到的第n个节点
		if(!root)
			return NULL;
		if(root->value==val){
			if(cnt){
				++*cnt;
				if(*cnt==n)
					return root;
			} else{
				return root;
			}
		}
		if(root->leftChild){
			auto ret = dtsBinaryTree::find_pre(root->leftChild,val,n,cnt);
			//cout<<"not find in left of "<<root->value<<endl;
			if(ret)
				return ret;
		}
		if(root->rightChild){
			auto ret = dtsBinaryTree::find_pre(root->rightChild,val,n,cnt);
			//cout<<"not find in right of "<<root->value<<endl;
			if(ret)
				return ret;
		}
		return NULL;
	}

	dtsBinaryTree<T>& add2Left(T val,dtsBinaryTreeNode<T>* parent){
		if(parent && !parent->leftChild){
			dtsBinaryTreeNode<T>* newNode=new dtsBinaryTreeNode<T>(val);
			parent->leftChild=newNode;
			//cout<<"add "<<val<<endl;
		}
		return *this;
	}
	dtsBinaryTree<T>& add2Right(T val,dtsBinaryTreeNode<T>* parent){
		if(parent && !parent->rightChild){
			dtsBinaryTreeNode<T>* newNode=new dtsBinaryTreeNode<T>(val);
			if(parent)
				parent->rightChild=newNode;
		}
		return *this;
	}
	dtsBinaryTree<T>& add2Left_val(T val,T parentVal,int n=1){
		return add2Left(val,dtsBinaryTree<T>::find_pre(root,parentVal,n));
	}
	dtsBinaryTree<T>& add2Right_val(T val,T parentVal,int n=1){
		return add2Right(val,dtsBinaryTree<T>::find_pre(root,parentVal,n));
	}

	void print_pre(){
		doSomethingTree_preOrder(root,[](dtsBinaryTreeNode<T>* node){
			cout<<node->value<<" ";
		});
		cout<<endl;
	}
	void print_in(){
		doSomethingTree_inOrder(root,[](dtsBinaryTreeNode<T>* node){
			cout<<node->value<<" ";
		});
		cout<<endl;
	}

	void print_post(){
		doSomethingTree_postOrder(root,[](dtsBinaryTreeNode<T>* node){
			cout<<node->value<<" ";
		});
		cout<<endl;
	}

	~dtsBinaryTree(){
		doSomethingTree_postOrder(root,[](dtsBinaryTreeNode<T>* node){
			delete node;
		});
	}

};

#endif
