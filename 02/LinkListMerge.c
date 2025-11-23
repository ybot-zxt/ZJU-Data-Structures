#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef int ElementType;
typedef struct NODE * List;
struct NODE {
    ElementType sequence_num;
    List   pNext;
};

typedef List PNODE;

PNODE create_new_list(void);
void traverse_list(PNODE pHead);

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = create_new_list();
    L2 = create_new_list();
    L = Merge(L1, L2);
    traverse_list(L);
    traverse_list(L1);
    traverse_list(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Merge( List L1, List L2){
    L1 = L1->pNext;
    L2 = L2->pNext;
    List Lhead = (List)malloc(sizeof(struct NODE));
    Lhead->pNext = NULL;
    List Ltail = Lhead;
    while(L1 != NULL && L2 != NULL){
        if(L1->sequence_num < L2->sequence_num){
            Ltail->pNext = L1;
            L1 = L1->pNext;
        }
        else{
            Ltail->pNext = L2;
            L2 = L2->pNext;
        }
        Ltail = Ltail->pNext;
        Ltail->pNext = NULL;
    }
    if (L1 != NULL) {
        Ltail->pNext = L1;
    } else {
        Ltail->pNext = L2;
    }
    return Lhead;
}





PNODE create_new_list(){

    int val;    // 链表数据域存放的数据
    int len;    // 链表长度
    int i = 0;  // 循环产生链表

    printf("请输入链表长度：\n");
    scanf("%d", &len);

    PNODE pHead = (PNODE)malloc(sizeof(struct NODE));  // 通过malloc分配一个头节点，malloc放在堆中，不会随着函数执行完毕而消失。
                                                // 同时分配一个头指针，最后要return pHead
    PNODE pTail = pHead;                        // 使用一个尾指针来
    pTail->pNext = NULL;                        // 确保尾指针即最后一个指针域是NULL

    for(i = 0; i < len; i++){
        
        // 接收val
        printf("请输入第%d项的值:\n", i+1);
        scanf("%d", &val);
        
        
        // 制作节点
        PNODE pNew = (PNODE)malloc(sizeof(struct NODE));
        pNew->sequence_num = val;

        // 把节点挂到pTail, pHead 上
        pTail->pNext = pNew;
        pTail = pNew;
        pNew->pNext = NULL;

    }

    return pHead;
}

void traverse_list(PNODE pHead){
    PNODE p_iter = pHead;
    p_iter = p_iter->pNext;
    while(p_iter != NULL){
        printf("%d ", p_iter->sequence_num);
        p_iter = p_iter->pNext;
    }
    printf("\n");
    return;
}