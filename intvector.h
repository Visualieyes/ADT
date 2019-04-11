/*
 *  Integer Vector ADT : public interface
 *
 *  Author:  Joseph Fall
 *  Date:    Jan. 8, 2018
 */

typedef struct  {
    int dim;
    int* vector;
} IntVector;

IntVector ivecFromArray( int dimension, int data[] );


void ivecPrint( IntVector v );

// Return true iff v1 has the same coordinate as v2
// PRE: v1.dim == v2.dim
bool ivecEqual( IntVector v1, IntVector v2 );

// Return a new vector, v, where v = v1 + v2
// PRE: v1.dim == v2.dim
IntVector ivecAdd( IntVector v1, IntVector v2 );

// Return a new vector, v, where v = v1 - v2
// PRE: v1.dim == v2.dim
IntVector ivecSubtract( IntVector v1, IntVector v2 );
