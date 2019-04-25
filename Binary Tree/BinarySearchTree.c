/*
 *  Binary Search Tree
 *
 *  Author:  Keyann Al-Kheder
 *  Date:    March 26, 2019
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


typedef Node_bt* bs_tree;



/*
 * Binary Search Tree Constructor Function:
 * returns a pointer to a new Node == NULL
 */
bs_tree createTree(){
	return NULL;
}


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
 * Returns True if tree is empty 
 */
bool isEmpty(bs_tree tree){
	return tree == NULL;
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


/*
 * Destructor Function:
 * Wrapper over destroyTree()
 * Post: Tree == NULL
 */
void destroy(bs_tree* tree_ref){
	bs_tree tree = *tree_ref;
	destroyTree(tree);
	*tree_ref = NULL;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
// Code taken from geeksforgeeks.org: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions//
//
// Function to print binary tree in 2D 
// Performs reverse in-order traversal 
void print2DUtil(bs_tree root, int space) 
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
   printf("\n\n");
}
// 
/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////




/*
 * Wrapper over print2D
 * Output representation of tree
 */
void printTree(bs_tree tree){
	print2D(tree);
}



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
 * Wrapper over treeSize()
 */
int Size(bs_tree tree){
	return (treeSize(tree));
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



/*
 * Wrapper over treeHeight()
 */
int Height(bs_tree tree){
	return treeHeight(tree);
}



/*
 * Instertion Function:
 * Append node with the given key into the tree
 * Post: Size(Tree) += 1
 */
void bst_Insert(bs_tree* tree_ref, int key){
	bs_tree root = *tree_ref;
	// If root is empty, insert at the root (Base Case) 
	if (root == NULL){
		*tree_ref = createNode(key);
	}
	else{

		//If the value stored is greater than our key
		if(root->data_key > key){ 

			//Move into the left node
			bst_Insert(&root->leftNode, key);
		}
		else{

			//Move into the right node
			bst_Insert(&root->rightNode, key);
		}
   	}
}



/*
 * Search Function
 * Find node with key K, and return it, otherwise NULL if it cant be found
 */
Node_bt* bst_Find(bs_tree tree, int k){
	if(tree == NULL){
		return NULL;
	}
	if(tree->data_key == k){
		return tree;
	}
	else{

		if(tree->data_key > k){
			return bst_Find(tree->leftNode, k);
		}
		else{
			return bst_Find(tree->rightNode, k);
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




  /////////////////////////////
 //     MAIN() Function     //
/////////////////////////////

int main( )
{

	//----- SAMPLE TEST DRIVER CODE -----
	int k;
	bs_tree tree = createTree();
	assert(isEmpty(tree));
	assert(Height(tree) == 0);
	bst_Insert(&tree, 10);
	bst_Insert(&tree, 13);
	bst_Insert(&tree, 7);

	printf("\nTree:\n");
	print2D(tree);

	assert(!isEmpty(tree));
	assert(Size(tree) == 3);
	assert(Height(tree) == 2);

	bst_Insert(&tree, 9);
	bst_Insert(&tree, 5);
	bst_Insert(&tree, 3);
	bst_Insert(&tree, 11);
	bst_Insert(&tree, 14);
	bst_Insert(&tree, 12);
	bst_Insert(&tree, 8);
	bst_Insert(&tree, 4);
	bst_Insert(&tree, 2);

	printf("\nTree:\n");
	print2D(tree);


	assert(Size(tree) == 12);
	assert(Height(tree) == 5);
	bst_Find(tree, 19);

	destroy(&tree);


	// //----- SAMPLE TEST DRIVER 2 CODE -----
	// //Initialize tree
	// binaryTree root = createNode(1);

	// //create child nodes
	// root->leftNode = createNode(2);
	// root->rightNode = createNode(3);

	// //append left child node
	// root->leftNode->leftNode = createNode(4);
	// root->leftNode->rightNode = createNode(5);

	// //append right child node
	// root->rightNode->leftNode = createNode(6);
	// root->rightNode->rightNode = createNode(7);

	// //append level 3 left child nodes
	// root->leftNode->leftNode->leftNode = createNode(8);

	// assert(treeSize(root) == 8);
	// assert(treeHeight(root->leftNode) == 3);

	// //Display Tree
	// print2D(root);
	// printf("\n");

	// //Destroy Tree
	// destroyTree(root);


	return 0;
}
