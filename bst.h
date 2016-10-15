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

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <time.h>
#include <vector>
using namespace std;

#pragma region defines

#ifdef __linux__// Linux
	#define CLEAR system("clear"); // Clear the comand prompt (screen)
	#define SLEEP sleep(1); // Make program pause for one sec
	#define KEYPRESS cout << "Press [Enter] to continue..."; cin.ignore(); // "Press [Enter] key to continue..."
	#define BOLD cout << "\033[1m";// Make text bold
	#define RED cout << "\033[31m";
	#define DEFCOLOR cout << "\033[39m";
#elif _WIN32// Windows
	#include <windows.h>	// Windows features
	#define CLEAR system("cls"); // Clear the comand prompt (screen)
	#define SLEEP Sleep(1000); // Make program pause for one sec
	#define KEYPRESS cout << "Press any key to continue..."; _getch(); // "Press any key to continue..."
	#define BOLD ""
	#define RED cout << "";
	#define DEFCOLOR ""
#endif

#define LINEBREAK cout << endl;// Line break
#define DEBUG false // For debugging
#define TEST true 	// For debugging

#pragma endregion

#ifndef BST_H
#define BST_H

#pragma region BST_Class

class Node{
	private:
		int data;
		Node* leftNode;
		Node* rightNode;
	public:
		// Setters
		void setleftNode(Node* left){
			leftNode = left;
		}
		void setrightNode(Node* right){
			rightNode = right;
		}
		void setData(int dat){
			data = dat;
		}
		// Getters
		Node* getleftNode(){
			return leftNode;
		}
		Node* getrightNode(){
			return rightNode;
		}
		Node* getNewNode(int);
		int getData(){
			return data;
		}
};

#pragma endregion

#pragma region functions

// Cases A, B, C
Node* delete_Case_A(Node* root, int data);
Node* delete_Case_B(Node* root, int data);
Node* delete_Case_C(Node* root, int data);

// Find Max & Min Node on BST
Node* minNode(Node*);
Node* maxNode(Node*);

// Insert Node & Print Tree Functions
Node* insertNode(Node* , int);
void printTree(Node*);

#pragma endregion

#endif