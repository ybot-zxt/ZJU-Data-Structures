#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coef;
    int exponent;
    struct Node * Next;
} Node, *List;

List create_new_list(); 
void traverse(List);
List Add(List, List);
List Attach(int coef, int expo, List tail);
List Mul(List, List);

int main(){
    List L1 = create_new_list();
    List L2 = create_new_list();
    List MulL = Mul(L1, L2);
    traverse(MulL);
    List AddL = Add(L1, L2);
    printf("\n");
    traverse(AddL);


    return 0;
}

// 成功运行
List create_new_list(){
    int len;
    int coef;
    int exponent;
    int i = 0;

    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    List tail = head;
    printf("Hello\n");
    scanf(" %d", &len);


    for (size_t i = 0; i < len; i++)
    {
        scanf(" %d %d", &coef, &exponent);
        List new = (List)malloc(sizeof(struct Node));

        new->coef = coef;
        new->exponent = exponent;

        tail->Next = new;
        tail = new;
        tail->Next = NULL;
    }

    return head;
}

// 成功运行
void traverse(List L){
    List p = L->Next;

    if( p == NULL){
        printf("0 0");
        return ;
    }
    while(p->Next != NULL){
        printf("%d %d ", p->coef, p->exponent);
        p = p->Next;
    }
    printf("%d %d", p->coef, p->exponent);

    return ;
}

// 成功运行
List Attach(int coef, int exponent, List tail){
    
    // 初始化新节点
    List new = (List)malloc(sizeof(struct Node));
    new->Next = NULL;

    // 新节点赋值
    new->exponent = exponent;
    new->coef = coef;

    // 将新节点与tail连接，更新tail
    tail->Next = new;
    tail = new;
    return tail;
}

// 成功运行
List Add(List L1, List L2){

    List p1 = L1->Next;
    List p2 = L2->Next;

    int sum = 0;

    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    List tail = head;
    while(p1 != NULL && p2 != NULL){
        if(p1->exponent > p2->exponent){
            tail = Attach(p1->coef, p1->exponent, tail);
            p1 = p1->Next;
        }
        else if(p1->exponent < p2->exponent){
            tail = Attach(p2->coef, p2->exponent, tail);
            p2 = p2->Next;
        }
        else{
            sum = p1->coef + p2->coef;
            if(sum != 0){
                tail = Attach(sum, p1->exponent, tail);
            }
            p1 = p1->Next;
            p2 = p2->Next;
        }
    }
    if(p1 == NULL){
        while(p2){
            tail = Attach(p2->coef, p2->exponent, tail);
            p2 = p2->Next;
        }
    }
    else if(p2 == NULL){
        while(p1){
            tail = Attach(p1->coef, p1->exponent, tail);
            p1 = p1->Next;
        }
    }

    return head;
}
// 成功运行
List Mul(List L1, List L2){
    
    // 准备好头节点和头指针
    List Thehead = (List)malloc(sizeof(struct Node));
    Thehead->Next = NULL;
    //List Thetail = head;

    // 准备好p1和p2
    List p1 = L1->Next;
    List p2 = L2->Next;

    // 准备好
    int mul_for_coef = 0;
    int mul_for_exponent = 0;
    while(p1){
        mul_for_coef = p1->coef;
        mul_for_exponent = p1->exponent;
        
        List adder_head = (List)malloc(sizeof(struct Node));
        adder_head->Next = NULL;
        List adder_tail = adder_head;
        // 遍历p2，使得head所在的链表是p2乘p1某一项
        while(p2){
            adder_tail = Attach(mul_for_coef * p2->coef, mul_for_exponent + p2->exponent, adder_tail);
            p2 = p2->Next;
        }
        p2 = L2->Next;
        Thehead = Add(adder_head, Thehead);

        p1 = p1->Next;
    }

    return Thehead;
}