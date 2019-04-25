/*
 *  Lab 8: Binary Tree
 *
 *  Author:  Keyann Al-Kheder
 *  Date:    March 19, 2018
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define COUNT 10



struct Node_s {
	int data_key;
	struct Node_s* leftNode;
	struct Node_s* rightNode;
};
typedef struct Node_s Node_bt; 


typedef Node_bt* binaryTree;

/*
 * Constructor Function:
 * returns a pointer to a new Node == NULL
 */
Node_bt* createNode(int data){
	Node_bt* newNode = malloc(sizeof(Node_bt));
	newNode->data_key =  data;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	return newNode;
}

/*
 * Helper Function
 * Print a text representation of a node
 */
void printNode(Node_bt* node){
	printf("%i", node->data_key);
}


/*
 * Destructor Function:
 * Free all nodes in a tree (Post-Order Traversal)
 * Post: Tree == NULL
 */
void destroyTree(Node_bt* tree){
	if(tree == NULL){
		return;  
	}
	else{
		destroyTree(tree->leftNode);
		destroyTree(tree->rightNode);
		free(tree);
	}
}




/////////////////////////////////////////////////////////////////////////////////////////////////
// Code taken from geeksforgeeks.org: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions//
//
// Function to print binary tree in 2D 
// Performs reverse in-order traversal 
void print2DUtil(binaryTree root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->rightNode, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printNode(root); 
  
    // Process left child 
    print2DUtil(root->leftNode, space); 
} 


// Wrapper over print2DUtil() 
void print2D(Node_bt* root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
}
// 
/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////



/*
 * returns the number of nodes in a tree
 */
int treeSize(Node_bt* tree){
	if (tree == NULL){
		return 0;
	}
	else{
		return 1 + treeSize(tree->rightNode) + treeSize(tree->leftNode);
	}
}



/*
 * return the level of the tree
 */
int treeHeight(Node_bt* subTree){
	if (subTree == NULL){
		return 0;
	}
	else{
		int left_height = treeHeight(subTree->leftNode);
		int right_height = treeHeight(subTree->rightNode);
		if (left_height > right_height){
			return 1 + treeHeight(subTree->leftNode);
		}
		else{
			return 1 + treeHeight(subTree->rightNode);
		}
	}

}



/*Post-Order Tree Traversal Function*/
int postTraverse(Node_bt* tree){
	if(tree == NULL){
		return 0;
	}
	else{
		/*Post-Order*/ return postTraverse(tree->leftNode) + postTraverse(tree->rightNode) + 1;
	}
}



/*Pre-Order Tree Traversal Function*/
int preTraverse(Node_bt* tree){
	if(tree == NULL){
		return 0;
	}
	else{
		/*Pre-Order*/return 1 + preTraverse(tree->leftNode) + treeSize(tree->rightNode);
	}

}

/*In-Order Tree Traversal Function*/
int inTraverse(Node_bt* tree){
	if(tree == NULL){
		return 0;
	}
	else{
		/*In-Order*/ return inTraverse(tree->leftNode) + 1 + inTraverse(tree->rightNode);
	}
}


  ///////////////////////
 //  MAIN() Function  //
///////////////////////
int main(){

	//Initialize tree
	binaryTree root = createNode(1);

	//create child nodes
	root->leftNode = createNode(2);
	root->rightNode = createNode(3);

	//append left child node
	root->leftNode->leftNode = createNode(4);
	root->leftNode->rightNode = createNode(5);

	//append right child node
	root->rightNode->leftNode = createNode(6);
	root->rightNode->rightNode = createNode(7);

	//append level 3 left child nodes
	root->leftNode->leftNode->leftNode = createNode(8);

	assert(treeSize(root) == 8);
	assert(treeHeight(root->leftNode) == 3);

	//Display Tree
	print2D(root);
	printf("\n");

	//Destroy Tree
	destroyTree(root);


	return 0;
}
