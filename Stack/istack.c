/*
 *  Integer Stack ADT: Basic Test Driver
 *
 *  Author:  Keyann Al-Kheder
 *  Date:    Mar. 11, 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "istack.h"

#define DUMMY_VALUE 694208008


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
 * Constructor - return a new, empty stack 
 * POST: istackIsEmpty(stack)
 */
IntStack_t istackCreate( ){
	Node_t* dummy = nodeCreate(DUMMY_VALUE);
	IntStack_t stack = {dummy};
	return stack;
}

/*
 * Destructor - empty stack and free all associated memory
 */
 void istackDestroy( IntStack_t *stack ){
 	assert(!istackIsEmpty(*stack));
 	while(stack->top->next != NULL){
 		Node_t* cur = stack->top->next;
 		stack->top->next = cur->next;
 		free(cur);
 	}
 } 

/*
 * Print a text representation of this stack on STDOUT
 */
void istackPrint( IntStack_t stack  ){
	Node_t* cur = stack.top->next;
	printf("\n\nTop\n");
	while (cur != NULL){
		printNode(cur);
		cur = cur->next;
	}
	printf("\n\n");
} 


/*
 * Helper Function:
 * Output a text representation of a node
 */
void printNode(Node_t* node){
	printf("[%d]\n%s\n", node->data, node->next ? " |\n V" : " |\n---"); //taken from your code in class
}

/*
 * Return true if the stack is empty
 */
bool istackIsEmpty( IntStack_t stack ){
	return stack.top->next == NULL;
}

/*
 * Return true iff the stack is full
 */
bool istackIsFull( IntStack_t stack ){
	return false;  //The stack is a linked-list implementation not an array
}

/*
 * Examine the item at the top of the stack
 * PRE: ! istackIsEmpty( stack )
 */
int istackTop( IntStack_t stack ){
	assert(!istackIsEmpty(stack));
	return stack.top->next->data;
}

/*
 * Pop the item from the top of the stack 
 * PRE: ! istackIsEmpty( stack )
 */
int istackPop( IntStack_t *stack ){
	assert(!istackIsEmpty(*stack));
	Node_t* removedNode = stack->top->next;
	int value = removedNode->data;
	stack->top->next = removedNode->next;
	free(removedNode);
	return value;
}

/*
 * Push given value on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
int istackPush( IntStack_t *stack, int value){
	Node_t* newNode = nodeCreate(value);
	newNode->next = stack->top->next;
	stack->top->next = newNode;
	return 0;
}
