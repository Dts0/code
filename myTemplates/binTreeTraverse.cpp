#include"dtsBinaryTree.hpp"
#include"dtsStack.hpp"
#include"dtsQueue.hpp"
using namespace std;

void traverse_pre(dtsBinaryTreeNode<int>* root){
	dtsStack<dtsBinaryTreeNode<int>*> stack;
	while(root || stack.top()){//必须栈空而且root也为空才结束
		while(root){
			cout<<root->value<<" ";
			stack.push(root);
			root=root->leftChild;
		}
		root=stack.pop();
		root=root->rightChild;
	}

}

void traverse_BFS(dtsBinaryTreeNode<int>* root){
	dtsQueue<dtsBinaryTreeNode<int>*> queue0;
	if(root)
		queue0.push(root);
	while(!queue0.empty()){
		//queue0.print();
		dtsBinaryTreeNode<int>* tmp=queue0.pop();
		cout<<tmp->value<<" ";
		//cout<<tmp->leftChild<<","<<tmp->rightChild<<endl<<endl;
		if(tmp->leftChild){
			queue0.push(tmp->leftChild);
		}
		if(tmp->rightChild){
			queue0.push(tmp->rightChild);
		}
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

	tree.print_pre();
	traverse_pre(root);
	cout<<endl;
	traverse_BFS(root);

	return 0;
}
