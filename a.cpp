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
#include <algorithm>
#define MAX_INS 1000000
#define MAX_DEL 100000

using namespace std;
int randNum();
void log();

int main(){
	ofstream file;
	file.open ("analysis.txt", ios_base::app);
	file << "\n++++++++++++++++++++++++++++++++++++++++\n";
	int TRIALS = 10;
	while(--TRIALS){
		srand(time(NULL));
		
		Node* root = NULL;
		
		// Creates random values
		vector<int> randNums;
		for (int i = 0; i < MAX_INS; i++)
			randNums.push_back(randNum());
		
		// Inserts nodes
		for (int i = 0; i < MAX_INS; i++){
			root = insertNode(root, randNums[i]);
		}
		//printTree(root);
		
		random_shuffle(randNums.begin(), randNums.end());
		const clock_t start = clock();
		for (int i = MAX_DEL; i >= 12; i--){
			delete_Case_A(root, randNums[i]);
		}
		const clock_t end = clock() - start;
		//printTree(root);
		float milliseconds = (end / (CLOCKS_PER_SEC / 1000));
		cout << "\nDeletion with A algorithm took ";
		cout << milliseconds << " ms & (" << end << " clicks)" << endl;
		file << "A algorithm took " << milliseconds << " ms  & (" << end << " clicks)\n";
	}
	file << "\n++++++++++++++++++++++++++++++++++++++++\n";
	file.close();
	
	return 0;
}
int randNum(){
	return (rand() % (MAX_INS - 1) + 1);
}