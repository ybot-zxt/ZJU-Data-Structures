#include<stdio.h>
#include<string.h>

typedef struct tree
{
    char data;
    int left;
    int right;
} tree, *node;

int traversals_using_stack(node, int);
void PostOrderTraversal(node, int);

#define null -1

int main(){


    // 步骤一：创造一个空树
    int tot_node = 0, root;
    scanf("%d", &tot_node);
    tree thetree[tot_node];

    // 步骤二：通过scanf遍历输入，完善数组储存的树
    root = traversals_using_stack(thetree, tot_node);

    // 步骤三：后序遍历输出
    PostOrderTraversal(thetree, root);

    return 0;
}

int traversals_using_stack(node T, int tot_node){

    // 初始化栈
    int stack[tot_node];
    int top = -1;

    // 初始化建树时的判断变量
    int root = -1;
    int last_node = -1; // 记录上一个操作的index
    int is_push = 0;    // 记录上一步是Push还是pop

    // 初始化建树时的其他变量
    int data;
    char buffer[5];
    int index = 0; // 储存在结构体数组中的下表
    int cnt = 0;



    // 初始化树的左右子树
    for(index = 0; index < tot_node; index++){
        T[index].left = null;
        T[index].right = null;
    }

    for (index = 0; cnt < 2 * tot_node; cnt++){
        scanf(" %s", buffer);

        if (strcmp("Push", buffer) == 0){       // Push INT
            scanf("%d", &data);

            T[index].data = data;

            if (root == -1){
                root = index;
            }
            else{                               // 根节点不考虑放到哪个子树里面
                if (is_push){                   // 上一步是push，data放在了栈顶元素的左边
                    T[stack[top]].left = index;
                }
                else{                           // 上一步是pop，data放在了被pop的元素中
                    T[last_node].right = index;
                }
            }

            stack[++top] = index;
            last_node = index;
            is_push = 1;
            index++;

        }
        else{
            last_node = stack[top];
            top--;
            is_push = 0;
        }
    }
    return 0;

}

void PostOrderTraversal(node T, int root){
    // 如果是
    if(root == null)
        return ;

    else{
        PostOrderTraversal(T, T[root].left);
        PostOrderTraversal(T, T[root].right);
        static int flag = 0;
        if (flag) printf(" ");
        printf("%d", T[root].data);
        flag++;
        }

    return ;
}