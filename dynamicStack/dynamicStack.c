#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct node_t{
    int data;
    struct node_t *pnext;
}node_t, *pnode_t;

typedef struct stack_t{
    pnode_t top;
    pnode_t bottom;
}stack_t, *pstack_t;


void StackInit(pstack_t pstack)
{
    pstack->bottom = malloc(sizeof(node_t));
    pstack->top    = pstack->bottom;
    pstack->top->pnext = NULL;
}


void StackShow(pstack_t ps)
{
    if(ps->bottom == ps->top)
    {
        printf("stack is blank\n");

        return;
    }

    pnode_t pt = ps->top;

    while(pt != ps->bottom)
    {
        printf("%d\n", pt->data);
        pt = pt->pnext;
    }

    return;
}


void StackPush(pstack_t ps, int val)
{
    pnode_t pnew = malloc(sizeof(pnode_t));
    pnew->data = val;
//    pnew->pnext = ps->top;
    pnew->pnext = NULL;
    ps->top = pnew;
}

void StackPop(pstack_t ps)
{
    if(ps->top == ps->bottom)
    {
        printf("stack is blank\n");
        return;
    }
    
    pnode_t tmp = ps->top;
    ps->top = ps->top->pnext;
    
    free(tmp);
    return;
}

void StackClear(pstack_t ps)
{
    while(ps->top != ps->bottom)
    {
        pnode_t tmp = ps->top;
        ps->top = ps->top->pnext;
        free(tmp);
    }
}

int main(void)
{
    stack_t stack;

    StackInit(&stack);
    StackPush(&stack, 6);
    StackPush(&stack, 7);
    StackPush(&stack, 8);
    StackShow(&stack);
    StackPop(&stack);
    StackShow(&stack);
    StackClear(&stack);
    StackShow(&stack);
    StackPush(&stack,7);
    StackShow(&stack);

    return 0;
}
