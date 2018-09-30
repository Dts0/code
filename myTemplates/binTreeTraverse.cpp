#include"dtsBinaryTree.hpp"
#include"dtsStack.hpp"
#include"dtsQueue.hpp"

void traverse_pre(dtsBinaryTreeNode<int>* root){
	//dtsBinaryTreeNode<int>* pRoot=root;
	dtsStack<dtsBinaryTreeNode<int>*> stack;
	while(root || stack.top()){//必须栈空而且root也为空才结束
		while(root){
			cout<<root->value<<" ";
			stack.push(root);
			root=root->leftChild;
		}
		root=stack.pop();
		root=root->rightChild;
		cout<<endl;
	}

//	cout<<stack.pop()->value<<endl;
//	cout<<stack.empty()<<endl;
	//root=pRoot;
}

void traverse_BFT(dtsBinaryTreeNode<int>* root){
	dtsQueue<dtsBinaryTreeNode<int>*> queue;
	while(root || queue.tail()){
		while(root){
			cout<<root->value<<" ";
			queue.push(root);
			root=root->leftChild;
		}
		root=queue.pop();
		root=root->rightChild;
	}
}

int main(){
	/*       0
	*     1      2
	*   3  6   4   5
	*/
/*
//debug for dtsList while try to find the reason why pTail and pBegin is not NULL
	dtsList<int> list;
	list.add2End(1)
		.add2Head(2);
	cout<<list.deleteFromEnd()<<endl;
	cout<<list.deleteFromHead()<<endl;
	cout<<list.deleteFromHead()<<endl;
*/

	dtsBinaryTreeNode<int>* root=new dtsBinaryTreeNode<int>(0);
	dtsBinaryTree<int> tree(root);
	tree.add2Left_val(1,0).add2Right_val(2,0).add2Left_val(3,1)
		.add2Left_val(4,2).add2Right_val(5,2).add2Right_val(6,1);

	//tree.print_pre();
	traverse_pre(root);
	cout<<endl;
	//traverse_pre(root);
	//traverse_BFT(root);


	return 0;
}
