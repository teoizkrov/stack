#include "hstack.h"
#include <stdlib.h>
int main( int argc, char *argv[] )
{

    return 0;
}

struct Stack
{
    int top; //the index of the top element
    int *a;
    int size;

};

struct Stack new_stack()
{
    struct Stack s;
    s.top = 0;
    s.size = 10;
    s.a = (int *) malloc( sizeof(int) * s.size ); 

    return s;
}

void push( struct Stack *stack, int data )
{
    if( stack->top >= stack->size )
        grow( stack );

    stack->a[stack->top++] = data;  
}

void grow( struct Stack *stack )
{
    stack->size *= 2;  
    stack->a = realloc( (int *) sizeof(int) * size );

}

