/*
 *  Lab 6: Excercise 5
 *    Sample applicaiton to Sort data from a data file.
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


//--------- SORT DATA FILE APP ------------
FILE* openFileRead(char* filename);
int readInt(FILE* fp);

int main(int argc, char* argv[])
{
   if (argc != 2) {
      printf("Usage: %s input-file-name \n", argv[0]);
      exit(-1);
   }

   LinkedList_t list = llCreate();
   
   FILE* fp= openFileRead(argv[1]);
   
   int i = readInt(fp);  // priming read
   while (! feof(fp)) {
      llInsertSorted(&list, i);
      i = readInt(fp);
   }

   printf("Successfully loaded list with %d elements.\n", llLength(list));
   llPrint(list);
   int prev = INT_MIN;
   printf("\n[ ");
   while (! llIsEmpty(list)) {
      int j = llPop(&list);
      printf("%d, ", j);
      if (prev > j) {
         printf("\nOops! List is not in sorted order: !( %d <= %d )\n", prev, j);
         assert(prev <= j);
      }
      prev = j;
   }
   printf("]\n");   
   printf("Data in List IS in sorted order! \n\n");
   return 0;
}

/*
 * Attempt to read / return an integer from an open file pointer, fp
 * May not return a valid value if eof is read, i.e., feof(fp)
 */
int readInt(FILE* fp) {
    int i;
    fscanf(fp, "%d", &i);
    return i;
}  

/*
 * Attempt to open the file for read access.
 * Peforms error check and exits if file is not accessible
 */
FILE* openFileRead(char* filename)
{
   FILE* inFile= fopen(filename, "r" );
   if( inFile== NULL) {
      printf( "Error opening input file %s, program terminating!\n", filename);
      exit(EXIT_FAILURE);
   }
   return inFile;
}
