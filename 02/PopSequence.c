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
    int maxsize;
    int currsize;
} STACK;

void init(STACK *);
void push(STACK *, int);
void check_popped_val(bool * flag, int next_to_pop, int popped_val);
bool pop(STACK * ps, int * pVal);
bool empty(STACK * ps);
void clear_stack(STACK * ps);

int main(){

    // 初始化一个空栈
    STACK s;
    init(&s);
    s.currsize = 0;

    printf("Hello\n");
    // 扫描第一行，为空栈增加限制
    int total_pop_sequences, sequence_length, cnt, next_to_pop, which_number_in_the_row, popped_val;
    scanf("%d %d %d", &(s.maxsize), &sequence_length, &total_pop_sequences);

    // 初始化输入的数组
    int sequence[sequence_length];
    for(int cnt = 0; cnt < sequence_length; cnt++)
        sequence[cnt] = cnt + 1;

    int * ptr = sequence;

    bool flag = true;
    
    for(cnt = 0; cnt < total_pop_sequences; cnt++){
        clear_stack(&s);
        for(which_number_in_the_row = 0; (which_number_in_the_row < sequence_length) && flag; which_number_in_the_row++){
            // 获得下一个需要pop的元素
            scanf(" %d", &next_to_pop);
            
            // 确保
            if(next_to_pop > sequence_length){
                flag = false;
                break;
            }

            // next_to_pop大于栈顶的元素,往里push直到栈满或push到next_to_pop
            if(next_to_pop > s.top->val){
                while(s.top->val != next_to_pop && s.currsize < s.maxsize){
                    push(&s, *ptr);
                    if(*ptr != sequence_length)
                        ptr++;
                }
                // 满了
                if (s.currsize == s.maxsize)
                    flag = false;
                else{
                    if(pop(&s, &popped_val))
                        check_popped_val(&flag, next_to_pop, popped_val);
                    else
                        flag = false;
                }
            }
            // 已经把大于等于next_to_pop的数压入栈中，不可能再通过压栈获得next_to_pop
            else{
                if(pop(&s, &popped_val))
                    check_popped_val(&flag, next_to_pop, popped_val);
                else
                    flag = false;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
        ptr = sequence;
        s.currsize = 0;
        flag = true;
    }


    return 0;
}


// 成功运行
void init(STACK * ps){
    // 建立空栈
    ps->top = (List)malloc(sizeof(struct Node));
    ps->bottom = ps->top;
    ps->bottom->Next = NULL;
    
    // 为空栈赋值，使得任何push的值都比它大
    ps->bottom->val = -1;

    return ;
}

// 成功运行
void push(STACK * ps, int val){
    List new = (List)malloc(sizeof(struct Node));
    new->val = val;

    new->Next = ps->top;
    ps->top = new;

    ps->currsize += 1;

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
        ps->currsize -= 1;
        return true;
    }
}

void check_popped_val(bool * flag, int next_to_pop, int popped_val){
    if(popped_val != next_to_pop)
        *flag = false;
    return ;
}

// 成功运行
bool empty(STACK * ps){
    if(ps->top == ps->bottom)
        return true;
    else
        return false;
}

void clear_stack(STACK * ps){
    int temp;
    while(!empty(ps)){
        pop(ps, &temp);
    }
}