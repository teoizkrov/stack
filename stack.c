#include "hstack.h"
int main( int argc, char* argv[] )
{

    return 0;
}

struct Stack
{
    int top; //the index of the top element
    int a[10];
    int size;

};

struct Stack new_stack()
{
    struct Stack s;
    s.top = 0;
    s.size = 10;
    return s;
}

void push( struct Stack* stack, int data )
{
    if( stack->top >= stack->size )
        grow( stack->a );

    stack->a[stack->top++] = data;  
}

void grow( int* a )
{
    return;
    
}
