/* C++ Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream> 

using namespace std; 

// A Binary Tree Node 
struct Node 
{ 
	struct Node *left, *right; 
	int key; 
}; 

// Utility function to create a new tree Node 
Node* newNode(int key) 
{ 
	Node *temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// This function returns pointer to LCA of two given values n1 and n2. 
// This function assumes that n1 and n2 are present in Binary Tree 
struct Node *findLCA(struct Node* root, int n1, int n2, int *ptrIsFound) 
{ 
	// Base case 
	if (root == NULL) return NULL; 

	// If either n1 or n2 matches with root's key, report 
	// the presence by returning root (Note that if a key is 
	// ancestor of other, then the ancestor key becomes LCA 
	if (root->key == n1 || root->key == n2) 
	{
    	(*ptrIsFound)++;
    	//if one key found and other not found they no need to return.This is special case when n1=10 and n2=12.
    	if(*ptrIsFound == 2)
    		return root;
    }

	// Look for keys in left and right subtrees 
	Node *left_lca = findLCA(root->left, n1, n2, ptrIsFound); 
	Node *right_lca = findLCA(root->right, n1, n2, ptrIsFound); 

	
	//Both the ptr valid - means its a LCA node so return its address
	//if(root->key == n1 || root->key == n2) ==> This is special case when n1=1 and n2=5.
	//At node 1 it should return node 1 address ; do not return node 5 address while coming back from 5
	if((left_lca && right_lca) || (root->key == n1 || root->key == n2))
		return root;
	else if(left_lca || right_lca)
		return (left_lca ? left_lca : right_lca);		
	else
		return NULL;

} 

// Driver program to test above functions 
int main() 
{ 
	// Let us create binary tree given in the above example 
	Node * root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 

	int i32IsFound = 0;
	int x=4,y=5;
	
	i32IsFound = 0;
	Node *lca = findLCA(root, x, y,&i32IsFound);
	cout << "LCA ("<< x << "," << y << ") = ";
	if(2 == i32IsFound)
		cout << lca->key << "\n";
	else
		cout << "Keys are not present \n",lca->key;

	x=4,y=10;	
	i32IsFound = 0;
	lca = findLCA(root, x, y,&i32IsFound);
	cout << "LCA ("<< x << "," << y << ") = ";
	if(2 == i32IsFound)
		cout << lca->key << "\n";
	else
		cout << "Keys are not present \n",lca->key;

	x=10,y=5;	
	i32IsFound = 0;
	lca = findLCA(root, x, y,&i32IsFound);
	cout << "LCA ("<< x << "," << y << ") = ";
	if(2 == i32IsFound)
		cout << lca->key << "\n";
	else
		cout << "Keys are not present \n",lca->key;

	return 0; 
}
/*
(base) root@abhijit:~/work_bench/geeksforgeeks/DS# g++ findLCA.cpp
(base) root@abhijit:~/work_bench/geeksforgeeks/DS# ./a.out 
LCA (4,5) = 2
LCA (4,10) = Keys are not present 
LCA (10,5) = Keys are not present 
*/
