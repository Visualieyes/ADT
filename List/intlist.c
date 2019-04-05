/*
Comp 220
Project: 1 
Author: Keyann Al-Kheder
Date: Feb.10.2019
*/



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "intlist.h"



/*
 * Constructor - return a new, empty list 
 * POST:  ilistLen(list) == 0
 */
IntList ilistNew( ){
	IntList list;

	list.capacity = 10;
	list.data = (int*)calloc(10, sizeof(int));
	list.len = 0;

	return list;
}


/* Return the number of items in the list */ 
int ilistLen( IntList list ){
	return list.len;
}

 /*
 * Print a text representation of this list on STDOUT
 */
void ilistPrint( IntList list  ){

	int i;

	for(i=0; i<list.len; i++){
		printf("list[%i] = %i\n", i, list.data[i]);
	}

}

/*
 * Append the given item to the list 
 * POST: ilistGet( ilistLen(list)-1 ) == item
 */
void ilistAppend( IntList *list, int item ){

	int length;

	if (listIsFull(list)){
		resizeList(list);
	}

	length = list->len;
	list->data[length] = item;
	list->len++;
}


/*
 * Returns True if the list is full, False otherwise.
 */
bool listIsFull(IntList* list){
	
	return list->len == list->capacity;

}

//expand list capacity
void resizeList( IntList * list ){

	list->data = realloc(list->data, (list->len + 10)*sizeof(int));
	list->capacity = list->len + 10;

}


/*
 * Insert the given item into the list at the given location
 * POST: length of list is increased by one, and ilistGet( list, at ) == item
 */
void ilistInsert( IntList *list, int at, int item ){

	ilistShiftRight(list, at);
	list->data[at] = item;
	list->len++;

}

// shift list elements, from index onward, 1 place to right,
// "creating" an "empty" slot at pos. index.
void ilistShiftRight( IntList *list, int index ){

	if (listIsFull(list)){
		resizeList(list);
	}

	int i;
	i = list->len; 

	while(i>index){
		list->data[i] = list->data[i-1];
		i--;
	}

	list->data[index] = (int)NULL;

}


/*
 * Remove the given item at the given location from the  list 
 * POST: length of list is reduced by one, item at given location has been removed.
 */
void ilistRemove( IntList *list, int at ){

	ilistShiftLeft(list, at);
	list->len--;
	list->data[list->len] = (int)NULL;

}



// shift list elements following index 1 place to left,
// "overwriting" the item at pos. index, shortening list by 1
void ilistShiftLeft( IntList *list, int index ){

	int i = index;
	int length = list->len;

	while(i < length-1){
		list->data[i] = list->data[i+1];
		i++; 
	}

}


/*
 * Search the list for the given item
 * RETURN: the position, pos, such that ilistGet(list, pos)==item OR -1 if the item is not found
 */
int ilistFind( IntList list, int item ){

	int i;

	while (i<list.len){
		if(list.data[i] == item){
			return i;
		}
		else{
			i++;
		}
	}

	return -1;

}



/*
 * Return the number of times the given item occurs in the list 
 */
int ilistCount( IntList list, int item ){

	int i;
	int count;

	for(i=0; i<list.len; i++){
		if (list.data[i] == item){
			count++;
		}
	}

	return count;

}



/*
 * Return the item at the given index from the list 
 * PRE: 0<=at && at<ilistLen(list)
 */
int ilistGet( IntList list, int at ){

	return list.data[at];
}




/*
 * Append all items from list2 to list1 
 * POST: length of list1 increased by size of list2 and all items from list2 are appended to list1.
 */
void ilistJoin( IntList *list1, IntList list2 ){
	int i;

	for (i=0; i<list2.len; i++){
		ilistAppend(list1, list2.data[i]);
	}
}


/*
 * Reverse the order of items in the list
 * POST: items in the list are in reversed order (e.g., first item is now last and visa versa)
 */
void ilistReverse( IntList *list ){
	int i, j, temp;

	i = 0;
	j = list->len-1;

	while (i <= j){
		temp = list->data[j];
		list->data[j] = list->data[i];
		list->data[i] = temp;
		i++;
		j--;
	}	
}



 /* Destructor - remove all data and free all memory associated with the list 
 * POST: ilistLen(list) == 0
 */
 void ilistDelete( IntList *list ){

 	int i;

 	for(i=0; i<list->len; i++){
 		list->data[i] = (int)NULL;
 	}

 	free(list->data);
 	list->data = NULL;
 	list->len = 0;
 	list->capacity = 0;
 }









