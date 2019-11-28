#include <stdio.h>
#include <stdlib.h>
#include "hstack.h"


int main( int argc, char *argv[] )
{


    return 0;
}



struct Node
{
    int data;
    struct Node *next;

};

struct Stack
{

    struct Node *top; // the head node
    int count;

};


struct Stack new_rstack()
{
    struct Stack s;
    s.top = NULL;
    s.count = 0;
    return s;
}

struct Node *new_node( int data )
{

    struct Node *temp = malloc( sizeof( struct Node ) );
    temp->data = data;
    return temp;

}

void push( struct Stack *s, int data )
{

    
    struct Node *n = new_node( data );
    n->next = s->top;
    s->top = n;
    
}
int pop( struct Stack *s )
{
    
    if( s->top != NULL )
    {
        struct Node *temp = s->top; 
        int poppedval = s->top->data;

        s->top = s->top->next;

        free( temp );
        return poppedval;
    }
    exit( 1 );

}

int peek( struct Stack *s )
{

    int temp = pop( s );
    push( s, temp );
    return temp;
    
}

int isempty( struct Stack *s )
{

    return s->top == NULL;

}








