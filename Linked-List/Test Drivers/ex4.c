/*
 *  Lab 6: Excercises 1 - 4
 *    Sample test driver for exercises 1 - 4 -- un-comment the relevant tests as you develop exercises 1 - 4
 *    Students must:  
 *        (1) supply the List ADT code
 *        (2) modify the main() program so calls to the List ADT match their code.
 *
 *  Author:  Joseph Fall
 *  Date:    Feb. 2, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

//------ STUDENT LIST ADT CODE GOES HERE ------


//----- TEST DRIVER -----
int main( )
{
   int v;
   Node_t* tmp;

   // Basic tests for Lab 5 List ADT
   LinkedList_t list = llCreate();
   assert(llIsEmpty(list));
   assert(llLength(list) == 0);
   assert(llFind(list, 1) == NULL);
   llAppend(&list, 1);
   llAppend(&list, 2);
   llAppend(&list, 3);
   llPrint(list);
   assert(!llIsEmpty(list));
   assert(llLength(list) == 3);
   assert(llFind(list, 2) != NULL);
   assert(llFind(list, 42) == NULL);
   llPush(&list, 99);
   llPush(&list, 98);
   llPush(&list, 97);
   llPrint(list);
   assert(llLength(list) == 6);
   assert(llFind(list, 2) != NULL);
   assert(llFind(list, 99) != NULL);
   v = llPop(&list);
   assert(v == 97);
   v = llPop(&list);
   assert(v == 98);
   llPrint(list);
   llDelete(&list);
   assert(llIsEmpty(list));
   /*
   // Ex. 1 Tests:  Link / Unlink (white-box tests)
   printf("\nLink / Unlink tests... \n");
   llLinkAfter(&list, list.head, nodeCreate(100));
   llLinkAfter(&list, list.head->next, nodeCreate(102));
   llLinkAfter(&list, list.head->next, nodeCreate(101));
   llLinkAfter(&list, list.tail, nodeCreate(103));
   llPrint(list);
   assert(llLength(list) == 4);
   assert(llUnlinkAfter(&list, list.tail) == NULL);
   assert(llLength(list) == 4);
   tmp = llUnlinkAfter(&list, list.head->next);
   llPrint(list);
   assert(llLength(list) == 3);
   assert(tmp->data == 101);
   free(tmp);
   
   tmp = llUnlinkAfter(&list, list.head->next->next);
   llPrint(list);
   assert(llLength(list) == 2);
   assert(tmp->data == 103);
   free(tmp);
 
   tmp = llUnlinkAfter(&list, list.head);
   llPrint(list);
   assert(llLength(list) == 1);
   assert(tmp->data == 100);
   free(tmp);
   llDelete(&list);
   assert(llIsEmpty(list));
   */
   /*
   // Ex. 3 Tests: Insert / Remove  
   printf("\nInsert / Remove tests... \n");
   llInsert(&list, list.head, 100);
   llInsert(&list, list.head->next, 102);
   llInsert(&list, list.head->next, 101);
   llInsert(&list, list.tail, 103);
   llPrint(list);
   assert(llLength(list) == 4);
   llRemove(&list, list.head->next->next);
   llPrint(list);
   assert(llLength(list) == 3);
   llRemove(&list, list.tail);
   llPrint(list);
   assert(llLength(list) == 2);
   llRemove(&list, list.head->next);
   llPrint(list);
   assert(llLength(list) == 1);
   llDelete(&list);
   assert(llIsEmpty(list));
   */
   /*
   // Ex. 4 Tests: Insert Sorted  
   printf("\nInsert Sorted tests... \n");
   llInsertSorted(&list, 203);
   llInsertSorted(&list, 204);
   llInsertSorted(&list, 201);
   llInsertSorted(&list, 202);
   llPrint(list);
   assert(llLength(list) == 4);
   v = llPop(&list);
   assert(v == 201);
   v = llPop(&list);
   assert(v == 202);
   llDelete(&list);
   assert(llIsEmpty(list));
   */
}
