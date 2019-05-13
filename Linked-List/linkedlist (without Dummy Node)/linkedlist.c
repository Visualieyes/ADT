/*
 *  Linked List
 *
 *  Author:  Keyann Al-Kheder
 *  Date:    Feb. 10, 2018
 */



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>



/*******************
 * PRIVATE TYPE DECLARATION
 ********************/
struct  Node {						
    int data;					//data contained in the node
    struct Node* next;			//pointer to the next node	
};									
typedef struct Node Node_t;	


/*******************
 * PRIVATE TYPE DECLARATION
 ********************/
struct list_s{
	Node_t* head;				//pointer to the head node
	Node_t*tail;				//pointer to the tail node
};
typedef struct list_s linkedList;



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
 * Constructor - return a new, empty list 
 * POST:  isEmpty(list) == NULL
 */
linkedList llCreate(){
	linkedList llist = {NULL, NULL};    // taken from the stanford link on moodle, for linked lists.
	return llist;
}


/*
 * Output a text representation of a node
 */
void printNode(Node_t*node){
	printf("[%d]%s", node->data, node->next ? "-->" : "--|"); //taken from your code in class
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
	return list.head == NULL;
}


/*
 * Append the given item to the list 
 * POST: Linked List list grows by 1 node, which the tail now points too.
 */
void llAppend(linkedList* list, int data){

	Node_t* newNode = nodeCreate(data);

	if (isEmpty(*list)){
		list->head = newNode;
	}
	else{
		list->tail->next = newNode;
	}
	list->tail = newNode;
}



/*
*	Destructor Function
*	POST: isEmpty(list) == True
*/
void llDelete(linkedList* list){
	
	Node_t* cur = list->head;

	while(cur != NULL){
		cur = cur->next;
		free(list->head);
		list->head = cur;
	}
	list->tail = NULL;
}



int main(){

	linkedList list = llCreate();

	// Tests
	assert(llIsEmpty(list) == true);
	assert(llLength(list) == 0);
	assert(llFind(list, 1) == NULL);
	llAppend(&list, 1);
	llAppend(&list, 2);
	llAppend(&list, 3);
	llPrint(list);
	assert(!llIsEmpty(list));
	printList(list);
	llDelete(&list);
	printList(list);

	return 0;
}			




