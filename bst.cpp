//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Name: Luis D. Chaparro
// Course: CSCE 3110_001
// Assignment: Program 3
// Due Date: 03/22/2016
// Description: Write a program to evaluate empirically the following strategies for
//				removing nodes with two children:
//				a. Replace with the largest node, X, in TL and recursively remove X.
//				b. Alternately replace with the largest node in TL and the smallest node
//				in TR, and recursively remove the appropriate node.
//				c. Replace with either the largest node in TL or the smallest node in
//				TR (recursively removing the appropriate node), making the choice randomly.
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "bst.h"

Node* getNewNode(int data){
	Node* newNode = new Node();
	newNode->setData(data);
	newNode->setleftNode(NULL);
	newNode->setrightNode(NULL);
	return newNode;
}
Node* insertNode(Node* root, int data){ 
	// If Tree is empty create root
	if(root == NULL) {
		root = getNewNode(data);
	}
	// if data is less or equal than root, insert in left subtree. 
	else if(data <= root->getData()) {
		root->setleftNode( insertNode(root->getleftNode(), data) );
	}
	// else, insert in right subtree. 
	else {
		root->setrightNode( insertNode(root->getrightNode(), data) );
	}
	return root;
}
void printTree(Node* node){
	cout << "Node " << node->getData() << " => ";
	if (node->getleftNode() == NULL)
		cout << "(NULL, ";
	else
		cout << "(" << node->getleftNode()->getData() << ", ";
	
	if (node->getrightNode() == NULL)
		cout << "NULL)" << endl;
	else
		cout << node->getrightNode()->getData() << ")" << endl;
	
	if (node->getleftNode() != NULL)
		printTree(node->getleftNode());
	if (node->getrightNode() != NULL)
		printTree(node->getrightNode());
}
Node* delete_Case_A(Node* root, int data){
	if (root == NULL)
		return root;
	else if (data < root->getData())
		root->setleftNode(delete_Case_A(root->getleftNode(), data));
	else if (data > root->getData())
		root->setrightNode(delete_Case_A(root->getrightNode(), data));
	else
		if (root->getleftNode() == NULL && root->getrightNode() == NULL){
			delete root;
			return NULL;
		}	
		else if (root->getleftNode() == NULL){
			Node *temp = root;
			root = root->getrightNode();
			delete temp;
		}	
		else if (root->getrightNode() == NULL){
			Node *temp = root;
			root = root->getleftNode();
			delete temp;
		}	
		else{
			Node *temp = minNode(root->getrightNode());
			root->setData(temp->getData());
			root->setrightNode(delete_Case_A(root->getrightNode(), temp->getData()));
		}
  return root;
}
Node* delete_Case_B(Node* root, int data){
	if (root == NULL)
		return root;
	else if (data < root->getData())
		root->setleftNode(delete_Case_B(root->getleftNode(), data));
	else if (data > root->getData())
		root->setrightNode(delete_Case_B(root->getrightNode(), data));
	else{
		if(root->getleftNode() == NULL && root->getrightNode() == NULL){
			delete root;
			return NULL;
		}
		else if (root->getleftNode() == NULL){
			Node *temp = root;
			root = root->getrightNode();
			delete temp;
		}
		else if (root->getrightNode() == NULL){
			Node *temp = root;
			root = root->getleftNode();
			delete temp;
		}
		else{
			Node *temp = maxNode(root->getleftNode());
			root->setData(temp->getData());
			root->setleftNode(delete_Case_B(root->getleftNode(), temp->getData()));
		}
	}
	return root;
}

Node* delete_Case_C(Node* root, int data){
	if (root == NULL)
		return root;
	else if (data < root->getData())
		root->setleftNode(delete_Case_C(root->getleftNode(), data));
	else if (data > root->getData())
		root->setrightNode(delete_Case_C(root->getrightNode(), data));
	else{
		if (root->getleftNode() == NULL && root->getrightNode() == NULL){
			delete root;
			return NULL;
		}
	
		else if (root->getleftNode() == NULL){
			Node *temp = root;
			root = root->getrightNode();
			delete temp;
		}
	
		else if (root->getrightNode() == NULL){
			Node *temp = root;
			root = root->getleftNode();
			delete temp;
		}
	
		else{
			srand(time(NULL));
			int random = rand() % 10;
			// Min
			if (random < 5) {
				Node *temp = minNode(root->getrightNode());
				root->setData(temp->getData());
				root->setrightNode(delete_Case_A(root->getrightNode(), temp->getData()));
			}
			// Max
			else {
				Node *temp = maxNode(root->getleftNode());
				root->setData(temp->getData());
				root->setleftNode(delete_Case_B(root->getleftNode(), temp->getData()));
			}	
		}
	}
	return root;
}
Node* minNode(Node* node){
	if (node->getleftNode() == NULL)
		return node;
	else
		return minNode(node->getleftNode());
}
Node* maxNode(Node* node){
	if (node->getrightNode() == NULL)
		return node;
	else
		return maxNode(node->getrightNode());
}