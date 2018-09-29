#include"dtsBinaryTree.hpp"
#include"dtsStack.hpp"

void traverse_pre(dtsBinaryTreeNode<int>* root){
	dtsStack<dtsBinaryTreeNode<int>*> stack;
	while(root){
		while(root){
			cout<<root->value<<",";
			stack.push(root);
			root=root->leftChild;
		}

		root=stack.pop();
		root=root->rightChild;
	}
}


int main(){
	/*       0
	*     1      2
	*   3  6   4   5
	*/
	dtsBinaryTreeNode<int>* root=new dtsBinaryTreeNode<int>(0);
	dtsBinaryTree<int> tree(root);
	tree.add2Left_val(1,0).add2Right_val(2,0).add2Left_val(3,1)
		.add2Left_val(4,2).add2Right_val(5,2).add2Right_val(6,1);

	tree.print_pre();
	traverse_pre(root);

	return 0;
}
