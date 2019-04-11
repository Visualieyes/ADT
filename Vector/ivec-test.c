/*
 *  Integer Vector ADT : test driver
 *
 *  Author:  Joseph Fall
 *  Date:    Jan. 8, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "intvector.h"


void scoreTestResult(bool testPassed, int *tests_passed) {
    if (testPassed) {
        printf("    ok \n");
        (*tests_passed)++;
    }
    else {
        printf("    TEST FAILED \n");
    }
}

void main() {
    int NUM_TESTS = 3;
    int tests_passed = 0;
    bool passed;
    
    int data1[] = {1, 2, 3};
    IntVector v1 = ivecFromArray(3, data1);
    
    printf("Test print vector: ");
    ivecPrint(v1);
    printf("\n");

// ---> TO DO:  Uncomment each test below as you implement each of the ivec operations

    // -------- ivecEqual tests ---------
    int data2[] = {1, 2, 3};
    IntVector v2 = ivecFromArray(3, data2);
    
    printf("Test Vector Equality? ");
    ivecPrint(v1);
    printf(" %s ", ivecEqual(v1, v2)?"==":"!=");
    ivecPrint(v2);

    scoreTestResult( ivecEqual(v1, v2), &tests_passed );


    // -------- ivecAdd tests ---------
    int data3[] = {19, 42, -6};
    IntVector v3 = ivecFromArray(3, data3);
    IntVector v4 = ivecAdd(v1, v3);
    
    printf("Test Vector Addition? ");
    ivecPrint(v1);
    printf(" + ");
    ivecPrint(v3);
    printf("=");
    ivecPrint(v4);

    int expectedSum[] = {20, 44, -3};
    IntVector expectedVec = ivecFromArray(3, expectedSum);

    scoreTestResult( ivecEqual(v4, expectedVec), &tests_passed );


    // -------- ivecSubtract tests ---------
    IntVector v5 = ivecSubtract(v4, v3);

    printf("Test Vector Subtraction? ");
    ivecPrint(v4);
    printf(" - ");
    ivecPrint(v3);
    printf("=");
    ivecPrint(v5);

    scoreTestResult( ivecEqual(v5, v1), &tests_passed );

    printf("\nPASSED: %d / %d  tests \n", tests_passed, NUM_TESTS);    
}




