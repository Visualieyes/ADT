/*
 *  Integer Vector ADT : private implementation
 *
 *  Author:  <Keyann Al-Kheder>
 *  Date:    Jan 30, 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "intvector.h"


// Initialize and return a vector from an array of values
IntVector ivecFromArray( int dimension, int data[] ) {
    int *vector = calloc(dimension, sizeof(int));
    int i;
    for (i=0; i<dimension; i++) {
        vector[i] = data[i];
    }
    
    IntVector v = {dimension, vector};
    return v;    
}


// Output vector
void ivecPrint(IntVector v) {   
    int i;

    for(i=0; i<v.dim; i++){
    	printf("V[%i] = %i\t", i, v.vector[i]);
    }
}


// Return true iff v1 has the same coordinate as v2
// PRE: v1.dim == v2.dim
bool ivecEqual( IntVector v1, IntVector v2 ){	
	int i;
	for(i=0; i<v1.dim; i++){
		if (v1.vector[i] != v2.vector[i]){
			return false;
		}
	}
	return true;
}


// Return a new vector, v, where v = v1 + v2
// PRE: v1.dim == v2.dim
IntVector ivecAdd( IntVector v1, IntVector v2 ){
	int n = v1.dim;
	int sum[n];

	int i;
	for (i=0; i<n; i++){
		sum[i] = v1.vector[i] + v2.vector[i];
	}
	return ivecFromArray(n, sum);
}


// Return a new vector, v, where v = v1 - v2
// PRE: v1.dim == v2.dim
IntVector ivecSubtract( IntVector v1, IntVector v2 ){
	int n = v1.dim;
	int sum[n];
	int i;

	for (i=0; i<n; i++){
		sum[i] = v1.vector[i] - v2.vector[i];
	}
	return ivecFromArray(n, sum);
	
}




int main(){
	return 0;
}





