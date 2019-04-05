/**
 *  Integer LIST ADT : public interface
 *
 *  COMP220: Assignment 1
 *  Author:  Joseph Fall
 *  Date:    Jan. 8, 2018
 */

#include <stdbool.h>
 
/*******************
 * PRIVATE TYPE DECLARATION
 ********************/
typedef struct  {
    int capacity;    // current list capacity -- currnt size of the data array -- current max. len of list
    int* data;       // the actual list data, a dyanmic, resizable array of int
    int len;         // the current length of the list -- the number of elements in the list
} IntList;

/*********************
 *  PUBLIC INTERFACE
 *********************/
 
/*
 * Constructor - return a new, empty list 
 * POST:  ilistLen(list) == 0
 */
IntList ilistNew( );

/*
 * Destructor - remove all data and free all memory associated with the list 
 * POST: ilistLen(list) == 0
 */
 void ilistDelete( IntList *list ); 


/*
 * Print a text representation of this list on STDOUT
 */
void ilistPrint( IntList list  ); 

/*
 * Return the number of items in the list
 */
int ilistLen( IntList list );

/*
 * Return the item at the given index from the list 
 * PRE: 0<=at && at<ilistLen(list)
 */
int ilistGet( IntList list, int at );


/*
 * Return the number of times the given item occurs in the list 
 */
int ilistCount( IntList list, int item );

/*
 * Search the list for the given item
 * RETURN: the position, pos, such that ilistGet(list, pos)==item OR -1 if the item is not found
 */
int ilistFind( IntList list, int item );


/*
 * Append the given item to the list 
 * POST: ilistGet( ilistLen(list)-1 ) == item
 */
void ilistAppend( IntList *list, int item );

/*
 * Insert the given item into the list at the given location
 * POST: length of list is increased by one, and ilistGet( list, at ) == item
 */
void ilistInsert( IntList *list, int at, int item );

/*
 * Remove the given item at the given location from the  list 
 * POST: length of list is reduced by one, item at given location has been removed.
 */
void ilistRemove( IntList *list, int at );

/*
 * Append all items from list2 to list1 
 * POST: length of list1 increased by size of list2 and all items from list2 are appended to list1.
 */
void ilistJoin( IntList *list1, IntList list2 );

/*
 * Reverse the order of items in the list
 * POST: items in the list are in reversed order (e.g., first item is now last and visa versa)
 */
void ilistReverse( IntList *list );

/*
 * Return a "deep copy" of the list, with it's own, independent set of data.
 * Challenge Exercise:  NOT required for assignment - add your own tests to test driver.
 */
IntList ilistCopy( IntList list );

/*
 * Returns True if the list is full, False otherwise.
 */
bool listIsFull( IntList *list );

//expand list capacity
void resizeList( IntList * list );

// shift list elements, from index onward, 1 place to right,
// "creating" an "empty" slot at pos. index.
void ilistShiftRight( IntList *list, int index );

// shift list elements following index 1 place to left,
// "overwriting" the item at pos. index, shortening list by 1
void ilistShiftLeft( IntList *list, int index );