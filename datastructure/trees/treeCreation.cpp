#include<iostream>

using namespace std;
struct Node {
	int data;
	Node *left;
	Node *right;
};

class Tree {
        public :
	Node *root;
	Tree(){
           root=NULL;	
	}
	void insert(int num);	
	int getRootNode();
	void preOrderTraversal(Node *ptr);
};

void Tree::insert(int num){
	//first creating the node so as to store the data in it 
	Node *newNode=new Node;
	newNode->data=num;
	newNode->left=NULL;
	newNode->right=NULL;
	//now trying to insert the new element in the tree
	//First we need to check if tree is empty
        if(root==NULL){
		//if tree is empty then this newly created node will become the root node
		root=newNode;
	}else {
		//since root node is not empty so we need to insert the node at correct position
		Node *ptr=root;
		//if value of traversing pointer doesn't become null till that time we will traverse
		while(ptr!=NULL){
			//we will compare the value of node data with current number 
			//if number is less then we check for left node
			//if number is more then we check for right node
			if(num > ptr->data){
				//now checking if right pointer is NULL or not 
				//if right pointer is null then we place the newely created node here
				//else we move the traversing pointer to next node
				if(ptr->right==NULL){
				  ptr->right=newNode;
				  ptr=NULL;
				}else {
				  ptr=ptr->right;
				}
			}else {
				if(ptr->left==NULL){
				  ptr->left=newNode;
				  ptr=NULL;
				}else {
				  ptr=ptr->left;
				}
			}

		}
	}	
}
int Tree::getRootNode(){
	//checking if root node is empty or not 
	if(root==NULL){
		cout << "Root Node is empty" << endl;
	}else {
	    return root->data;
	}
	return -1;
}


void Tree::preOrderTraversal(Node *pt){	
	Node *ptr=pt;
	if(ptr==NULL){
		return;
	}else{
		cout << ptr->data<<endl;
		preOrderTraversal(ptr->left);
		preOrderTraversal(ptr->right);
	}
	
}



int main(){
	Tree bst;
	bst.insert(6);
	bst.insert(1);
	bst.insert(9);
	bst.insert(4);
	bst.preOrderTraversal(bst.root);
}

