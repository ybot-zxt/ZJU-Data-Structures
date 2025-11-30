#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    char data;
    int left;
    int right;
} tree, *node;

int build_tree(node);
void traverse_leaves(node, int);

#define null -1

int main(){
    tree TheTree[10];
    int root = build_tree(TheTree);

    traverse_leaves(TheTree, root);

    return 0;
}

int build_tree(node the_tree){
    
    int tot_node = 0;
    scanf("%d", &tot_node);
    if (tot_node == 0) return null;
    
    int check[10], i = 0;
    for (i = 0; i < 10; i++)
        check[i] = 0;

    // 构建数组
    char left, right, data; 
    for (i = 0; i < tot_node; i++){
        scanf(" %c %c", &left, &right);

        // data left right 进入数组
        the_tree[i].data = i;      // data进入数组
        
        // left进入数组
        if (left != '-'){
            the_tree[i].left = left - '0';
            check[the_tree[i].left] = 1;
        }
        else
            the_tree[i].left = null;

        // right进入数组
        if (right != '-'){
            the_tree[i].right = right - '0';
            check[the_tree[i].right] = 1;
        }
        else
            the_tree[i].right = null;
    }

    for (i = 0; i < tot_node; i++){
        if(check[i] == 0)
            return i;
    }

    return null;
}

void traverse_leaves(node T, int root){
    // 步骤一：初始化队列，让第一个元素是root，其他的都是-1
    int Queue[10];
    int front = -1;
    int rear = -1;
    int i = 0;
    for (i = 0; i < 10; i++)
        Queue[i] = null;
    Queue[0] = root;
    ++rear;


    // 这是普通的层序遍历
    /*

    for (i = 0; Queue[i] != null; i++){
        printf("%d ", T[Queue[i]].data);
        
        // 把左子树下表放到队列里
        if (T[Queue[i]].left != null)
            Queue[++rear] = T[Queue[i]].left;
    
        if (T[Queue[i]].right != null)
            Queue[++rear] = T[Queue[i]].right;
    }
    */
    // 
    // 步骤二：使用队列开始遍历。
    int flag = 0;                                                   // 输出格式控制
    for (i = 0; i <= rear; i++){
        if(T[Queue[i]].left == null && T[Queue[i]].right == null){  // 只需在普通的层序遍历前面加上条件判断即可
            if(flag) printf(" ");  
            printf("%d", T[Queue[i]].data);
            flag = 1;
            continue;
        }   

        
        // 把左子树下表放到队列里
        if (T[Queue[i]].left != null){
            if (rear + 1 >= MAX_Q_SIZE) {
                printf("Error: Queue Overflow!\n");     // 错误处理：虽然这道题不应该发生，但工程上必须有这行
                return; 
                }
            
            Queue[++rear] = T[Queue[i]].left;                       // 依赖数据分布来保证内存安全！！！
        }


    
        if (T[Queue[i]].right != null){
            if (rear + 1 >= 10) {
                printf("Error: Queue Overflow!\n");     // 错误处理：虽然这道题不应该发生，但工程上必须有这行
                return; 
                }
            
            Queue[++rear] = T[Queue[i]].right;                       // 依赖数据分布来保证内存安全！！！
        }
    }

    return ;
    
}