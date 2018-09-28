#include<iostream>
#include<functional>

using namespace std;

template <typename T>
class BinaryTreeNode{
public:
	T value;
	BinaryTreeNode<T>* leftChild;
	BinaryTreeNode<T>* rightChild;
	BinaryTreeNode(T val,BinaryTreeNode<T>* left=NULL,BinaryTreeNode<T>* right=NULL)
				:value(val),leftChild(left),rightChild(right){}
	BinaryTreeNode(){}
};

//后序遍历并执行函数func

template <typename T>
class BinaryTree{
	BinaryTreeNode<T>* root;
	//前序遍历
	static void doSomethingTree_preOrder(BinaryTreeNode<T>* root,function<void(BinaryTreeNode<T>* node)> func){
	if(!root)
		return;
	func(root);
	if(root->leftChild)
		BinaryTree::doSomethingTree_preOrder(root->leftChild,func);
	if(root->rightChild)
		BinaryTree::doSomethingTree_preOrder(root->rightChild,func);
	}
	//中序遍历
	static void doSomethingTree_inOrder(BinaryTreeNode<T>* root,function<void(BinaryTreeNode<T>* node)> func){
	if(!root)
		return;
	if(root->leftChild)
		BinaryTree::doSomethingTree_inOrder(root->leftChild,func);
	func(root);
	if(root->rightChild)
		BinaryTree::doSomethingTree_inOrder(root->rightChild,func);
	}
	//后序遍历
	static void doSomethingTree_postOrder(BinaryTreeNode<T>* root,function<void(BinaryTreeNode<T>* node)> func){
	if(!root)
		return;
	if(root->leftChild)
		BinaryTree::doSomethingTree_postOrder(root->leftChild,func);
	if(root->rightChild)
		BinaryTree::doSomethingTree_postOrder(root->rightChild,func);
	func(root);
	}

public:
	BinaryTree(T rootValue){
		root=new BinaryTreeNode<T>(rootValue);
	}
	BinaryTree(BinaryTreeNode<T>* rt):root(rt){}

	static BinaryTreeNode<T>* find_pre(BinaryTreeNode<T>* root,T val,int n=1,int* cnt=NULL){//返回前序遍历找到的第n个节点
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
			auto ret = BinaryTree::find_pre(root->leftChild,val,n,cnt);
			//cout<<"not find in left of "<<root->value<<endl;
			if(ret)
				return ret;
		}
		if(root->rightChild){
			auto ret = BinaryTree::find_pre(root->rightChild,val,n,cnt);
			//cout<<"not find in right of "<<root->value<<endl;
			if(ret)
				return ret;
		}
		return NULL;
	}

	BinaryTree<T>& add2Left(T val,BinaryTreeNode<T>* parent){
		if(parent && !parent->leftChild){
			BinaryTreeNode<T>* newNode=new BinaryTreeNode<T>(val);
			parent->leftChild=newNode;
			//cout<<"add "<<val<<endl;
		}
		return *this;
	}
	BinaryTree<T>& add2Right(T val,BinaryTreeNode<T>* parent){
		if(parent && !parent->rightChild){
			BinaryTreeNode<T>* newNode=new BinaryTreeNode<T>(val);
			if(parent)
				parent->rightChild=newNode;
		}
		return *this;
	}
	BinaryTree<T>& add2Left_val(T val,T parentVal,int n=1){
		return add2Left(val,BinaryTree<T>::find_pre(root,parentVal,n));
	}
	BinaryTree<T>& add2Right_val(T val,T parentVal,int n=1){
		return add2Right(val,BinaryTree<T>::find_pre(root,parentVal,n));
	}

	void print_pre(){
		doSomethingTree_preOrder(root,[](BinaryTreeNode<T>* node){
			cout<<node->value<<" ";
		});
		cout<<endl;
	}
	void print_in(){
		doSomethingTree_inOrder(root,[](BinaryTreeNode<T>* node){
			cout<<node->value<<" ";
		});
		cout<<endl;
	}

	void print_post(){
		doSomethingTree_postOrder(root,[](BinaryTreeNode<T>* node){
			cout<<node->value<<" ";
		});
		cout<<endl;
	}

	~BinaryTree(){
		doSomethingTree_postOrder(root,[](BinaryTreeNode<T>* node){
			delete node;
		});
	}

};


/*
         0
	1        2
  3  4     5  6
7     8

*/
int main(){

	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(0);
	BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node3=new BinaryTreeNode<int>(3);
	BinaryTreeNode<int>* node4=new BinaryTreeNode<int>(4);
	BinaryTreeNode<int>* node5=new BinaryTreeNode<int>(5);
	BinaryTreeNode<int>* node6=new BinaryTreeNode<int>(6);
	BinaryTreeNode<int>* node7=new BinaryTreeNode<int>(7);
	BinaryTreeNode<int>* node8=new BinaryTreeNode<int>(8);

	root->leftChild=node1;
	root->rightChild=node2;
	node1->leftChild=node3;
	node1->rightChild=node4;
	node3->leftChild=node7;
	node4->rightChild=node8;
	node2->leftChild=node5;
	node2->rightChild=node6;


	BinaryTree<int> tree0(root);
	tree0.print_pre();//前序遍历
	tree0.print_in();//中序遍历
	tree0.print_post();//后序遍历
	cout<<endl;

//两种使用方法
/*
         0
	1        2
  3  4     5  6
7     8

*/

	BinaryTree<int> tree(0);
	tree.add2Left_val(1,0).add2Right_val(2,0).add2Left_val(3,1).add2Right_val(4,1).add2Left_val(5,2).add2Right_val(6,2)
		.add2Left_val(7,3).add2Right_val(8,4);
	tree.print_pre();//前序遍历
	tree.print_in();//中序遍历
	tree.print_post();//后序遍历

	return 0;
}
