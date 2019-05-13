/**
 *  Integer Stack ADT : public interface
 *    Choose your implementation of a stack
 *
 *  COMP220: Lab 7 Solution
 *  Original Author:  Joseph Fall 
 *  Modified by:  Keyann Al-Kheder
 *  Date:    Mar. 10, 2019
 */


/*******************
 * PRIVATE TYPE DECLARATION
 ********************/

struct Node_s
{
	int data;
	struct Node_s* next;
};
typedef struct Node_s Node_t;


struct stack_s
{
	Node_t* top;
};
typedef struct stack_s IntStack_t;


/*********************
 *  PUBLIC INTERFACE
 *********************/

/*
 * Constructor - return a node 
 * POST:  Node: [Value][NULL-]
 */
Node_t* nodeCreate(int value);
 
/*
 * Constructor - return a new, empty stack 
 * POST: istackIsEmpty(stack)
 */
IntStack_t istackCreate( );

/*
 * Destructor - empty stack and free all associated memory
 */
 void istackDestroy( IntStack_t *stack ); 

/*
 * Print a text representation of this stack on STDOUT
 */
void istackPrint( IntStack_t stack  ); 


/*
 * Helper Function for istackPrint
 * Print a text representation of a node on STDOUT
 */
void printNode( Node_t* node );

/*
 * Return true iff the stack is empty
 */
bool istackIsEmpty( IntStack_t stack );

/*
 * Return true iff the stack is full
 */
bool istackIsFull( IntStack_t stack );

/*
 * Examine the item at the top of the stack
 * PRE: ! istackIsEmpty( stack )
 */
int istackTop( IntStack_t stack );

/*
 * Pop the item from the top of the stack 
 * PRE: ! istackIsEmpty( stack )
 */
int istackPop( IntStack_t *stack );

/*
 * Push given item on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
int istackPush( IntStack_t *stack, int item);
