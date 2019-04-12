/*
 *  Linked-List
 *
 *  Author:  Keyann Al-Kheder
 *  
 */



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "linkedList.h"




//------ Node --------
/*
 * Constructor - return a node 
 * POST:  Node: [Value][NULL-]
 */
Node_t* nodeCreate(int value) {
  Node_t* node = malloc(sizeof(Node_t));
  node->data = value;
  node->next = NULL;
  return node;
}


/*
 * Output a text representation of a node
 */
void printNode(Node_t*node){
	printf("[%d]%s", node->data, node->next ? "-->" : "--|"); //taken from your code in class
}




//------ List ---------
/*
 * Constructor - return a new, empty list 
 * POST:  isEmpty(list) == NULL
 */
linkedList llCreate(){
	Node_t* dummy = nodeCreate(DUMMY_SIZE);
	linkedList llist = {dummy, dummy};  
	return llist;
}

/*
*	Destructor Function
*	POST: isEmpty(list) == True
*/
void llDelete(linkedList* list){
	while(list->head->next != NULL){
		Node_t* cur = list->head->next;
		list->head->next = cur->next;
		free(cur);
	}
	list->tail = list->head;
}



/*
 * Output a text representation of the list
 */
void printList(linkedList list){
	Node_t* cur = list.head;
	printf("\nList:  ");

	while (cur != NULL){
		printNode(cur);
		cur = cur->next;
	}
	printf("\n\n");
}


/*
 * Returns True is the list is empty, False otherwise 
 */
bool isEmpty(const linkedList list){
	return list.head->next == NULL;
}



/*
 * Instert a node (newNode) following the cursor node (cur) 
 * Post: llLength(list) = llLength(llLength) + 1
 */
void llLink(linkedList* list, Node_t* cur, Node_t* newNode){
	newNode->next = cur->next;
	cur->next = newNode;
	if(newNode->next == NULL){
		list->tail = newNode;
	}
}


/*
 * Append the given item to the list 
 * POST: Linked List list grows by 1 node, which the tail now points too.
 */
void llAppend(linkedList* list, int data){
	Node_t* newNode = nodeCreate(data);

	list->tail->next = newNode;
	list->tail = newNode;
}



/*
 * Returns a pointer to the previous to node  
 */
Node_t* findPrevNode(linkedList* list, Node_t* node){
	Node_t* cur = list->head;
	while(cur->next != node){
		cur = cur->next;
	} 
	return cur;
}


/* 
 * Helper Function for insertSorted()
 * Returns a pointer to the node just prior where value < node.data 
 */
Node_t* findInsertionPoint(linkedList* list, int value){
	Node_t* cur = list->head;

	while(cur->next != NULL){
		if(cur->next->data > value){
			return cur;
		}
		else{
			cur = cur->next;
		}
	}
	return cur;
}


/*
 * Remove the node (cur) from linkedList
 * PRE: cur != list->head. It is illegal to remove the dummy head node
 */
void removeNode(linkedList* list, Node_t* cur){
	assert(cur != list->head);
	Node_t* prevNode = findPrevNode(list, cur);
	prevNode->next = cur->next;
	free(cur);
	if(prevNode->next == NULL){
		list->tail = prevNode->next;
	}

}


/*
 * Insert (push) a newNode on to the head of a linkedList
 * newNode.data == value
 * POST: llLength(list) = llLength(list) + 1 
 */
void llPush(linkedList* list, int value){
	Node_t* newNode = nodeCreate(value);
	newNode->next = list->head->next;
	list->head->next = newNode;
}


/*
 * Remove the head node from a list and return its value
 * PRE: isEmpty(list) == FALSE
 * POST: llLength(list) = llLength(list) + 1 
 */
int llPop(linkedList* list){
	assert(!isEmpty(*list));
	Node_t* node = list->head->next;
	int value = node->data;
	removeNode(list, node);
	return value;
}


/*
 * Insert a new node, where node.data == value, just following the node (cur) 
 * PRE: value != 694208008
 * POST: llLength(list) = llLength(list) + 1 
 */
void insertAfter(linkedList* list, Node_t* cur, int value){
	assert(list->head->data != value);
	llLink(list, cur, nodeCreate(value));
}


/*
 * Insert a value into the list just prior to the first node where value < Node.data
 * POST: llLength(list) = llLength(list) + 1 
 */

void llInsertSorted(linkedList* list, int value){
	Node_t* prevNode = findInsertionPoint(list, value);
	insertAfter(list, prevNode, value);
}




