#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int val;
    struct Node * Next;
} * List;

typedef struct stack{
    List top;
    List bottom;
} STACK;

void init(STACK *);
void push(STACK *, int);
void traverse(STACK);
bool empty(STACK *); 
bool pop(STACK *, int *);

int main(){
    STACK S;
    int val;
    init(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    traverse(S);
    if(pop(&S, &val))
        printf("出栈成功，出栈的元素是：%d\n", val);
    else
        printf("出栈失败！\n");
    traverse(S);
    return 0;
}

// 成功运行
void init(STACK * ps){
    ps->top = (List)malloc(sizeof(struct Node));
    ps->bottom = ps->top;

    ps->bottom->Next = NULL;

    return ;
}

// 成功运行
void push(STACK * ps, int val){
    List new = (List)malloc(sizeof(struct Node));
    new->val = val;

    new->Next = ps->top;
    ps->top = new;

    return ;
}

// 成功运行
void traverse(STACK s){
    while(s.top != s.bottom){
        printf("%d ", s.top->val);
        s.top = s.top->Next;
    }

    return ;
}

// 成功运行
bool pop(STACK * ps, int * pVal){
    if(empty(ps)){
        return false;
    }
    else{
        List r = ps->top;
        *pVal = r->val;
        ps->top = ps->top->Next;
        free(r);
        r = NULL;
        return true;
    }
}

// 成功运行
bool empty(STACK * ps){
    if(ps->top == ps->bottom)
        return true;
    else
        return false;
}