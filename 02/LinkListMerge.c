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
/*
L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。
直接使用原序列中的结点说明是原地修改，把L1L2指针域的内容完全重写。Merge函数执行完后，L1L2指针变量还在，也依旧执行Merge函数前的头节点，但是L1L2再也不是曾经的结构了。
因此L1->Next = NULL是为了安全，避免你去操作一些不知道会指向什么内容的指针。这也引出了使用头节点的一些好处：
如果先通过比较确定L1还是L2当L的头指针得先看L1L2的next是不是null，后续遍历的差不多了还得再判断一遍，最后还得判断L1L2哪个可以使用安全声明L1->Next = NULL设为NULL。
*/




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