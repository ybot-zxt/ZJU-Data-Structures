#include<stdio.h>

typedef struct TreeNode{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
    
} * BinTree, TreeNode;

void PreOrderTraversal(BinTree);
void InOrderTraversal(BinTree);



void PreOrderTraversal(BinTree BT){
    if(BT){
        printf("%d", BT->data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}


void InOrderTraversal(BinTree BT){
    if(BT){
        InOrderTraversal(BT->left);
        printf("%d", BT->data);
        InOrderTraversal(BT->right);
    }
}