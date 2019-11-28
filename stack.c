#include "hstack.h"
#include <stdlib.h>
#include <stdio.h>

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
    s.a = (int *) malloc( sizeof( int ) * s.size ); 

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
    stack->a = (int *) realloc( stack->a, sizeof( int ) * stack->size );
    printf( "I HAVE GROWN \n" );

}
void shrink( struct Stack *stack )
{
    stack->size /= 2;
    stack->a = ( int * ) realloc( stack->a, sizeof( int ) *stack->size );
    printf( "I HAVE SHRUNK \n" );

    
}
int isempty( struct Stack *stack )
{

   return stack->top == 0; 

}
int pop( struct Stack *stack )
{

    if( stack->top <= stack->size / 3 && stack->size > 10 )
        shrink( stack );

    return stack->a[stack->top--];
}

int main( int argc, char *argv[] )
{
    
    struct Stack s = new_stack();

    int i;
    for( i=0; i < 20; i++ )
        push( &s, i );
    
    printf( "%d\n", s.size );
    
    for( ; i > 0; i-- )
        printf( "%d\n", pop( &s ));
    
    printf( "%d\n", s.top );
    printf( isempty( &s ) ? "IT'S EMPTY BOSS\n" : "IT AIN'T EMPTY BOSS\n" );



    free( s.a );

    return 0;
}













