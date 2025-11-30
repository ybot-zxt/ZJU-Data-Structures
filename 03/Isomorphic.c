#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    char data;
    int left;
    int right;
} tree, *node;

int build_tree(node);
int IsOmorphic(node, int, node, int);
#define null -1

int main(){
    tree first_tree[10], second_tree[10];
    int first_root, second_root;

    // 步骤一：制作两个树节点，返回root的值
    first_root = build_tree(first_tree);
    second_root = build_tree(second_tree);

    // 步骤二：判断是否同构
    if(IsOmorphic(first_tree, first_root, second_tree, second_root))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

int build_tree(node T){
    int tot_node = 0;
    int root;

    scanf(" %d", &tot_node);
    if (tot_node == 0) return -1;

    // 步骤一：接收那tot_node个节点
    char left, right;
    int i = 0;
    int check[tot_node];

    for(i = 0; i < tot_node; i++)
        check[i] = 0;
    for(i = 0; i < tot_node; i++){
        // 把输入的字符正确的放到T里面
        scanf(" %c %c %c", &T[i].data, &left, &right);
        if(left != '-'){
            T[i].left = left - '0';     
            check[T[i].left] = 1;       
        }
        else
            T[i].left = null;

        if(right != '-'){
            T[i].right = right - '0';     
            check[T[i].right] = 1;       
        }
        else
            T[i].right = null;

    }

    // 判断哪一项是root
    for(root = 0; root < tot_node; root++){
        if(check[root] == 0)
            return root;
    }
    return null;
}

int IsOmorphic(node first_tree, int first_root, node second_tree, int second_root){
    // 1. 两个都是空树
    if (first_root == null && second_root == null) 
        return 1;

    // 2. 一个空一个不空
    if ((first_root == null && second_root != null) || (first_root != null && second_root == null))
        return 0;

    // 3. 两个都不空，判断根和左右子树

    // 3.0 判断根节点
    if (first_tree[first_root].data != second_tree[second_root].data)
        return 0;

    // 3.1 判断左子树: 均是空的，直接比较又子树
    if ((first_tree[first_root].left == null) && (second_tree[second_root].left == null))
        return IsOmorphic(first_tree, first_tree[first_root].right, second_tree, second_tree[second_root].right);
    
    // 3.2 判断左子树: 均是不空的，且无需交换，直接比较左和右子树
    if (((first_tree[first_root].left != null) && second_tree[second_root].left != null) && (first_tree[first_tree[first_root].left].data == second_tree[second_tree[second_root].left].data))
        return (IsOmorphic(first_tree, first_tree[first_root].left, second_tree, second_tree[second_root].left) && IsOmorphic(first_tree, first_tree[first_root].right, second_tree, second_tree[second_root].right));
    
    // 3.3
    else
        return (IsOmorphic(first_tree, first_tree[first_root].left, second_tree, second_tree[second_root].right) && IsOmorphic(first_tree, first_tree[first_root].right, second_tree, second_tree[second_root].left));
}