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
    // 初始化一个栈
    int stack[tot_node];
    int top = 0;

    // 初始化其他变量
    int change_to_left_branch = 1; // 判断该放到left或right里面
    char buffer[4] = "";    // 初始化一个存放push, pop字符的字符数组
    char temp_data;
    int is_root = 1;
    int cnt = 0;
    int index = 0;

    // 初始化树的左右子树
    for(index = 0; index < tot_node; index++){
        T[index].left = null;
        T[index].right = null;
    }

    for (index = 0; cnt < 2 * tot_node; cnt++){
        scanf(" %s", &buffer);
        // 入栈，
        if (strcmp(buffer, "Push") == 0){
            scanf(" %c", &temp_data);
            change_to_left_branch = 1;
            // 如果是根节点，只需考虑填自身的结构体，无需连接父节点
            if(is_root){
                stack[top] = 0;
                T[index].data = temp_data - '0';
                index++;
                is_root = 0;
            }
            // 非根节点，不但要填自己的data，还要根据栈找到父节点，连接正确的子树
            else{
                // 父节点填入正确的left或right
                if (change_to_left_branch){     // 如果现在是左子树，那么先找到栈中上一个节点，它是父节点地址，父节点处的left设为树的index
                    T[stack[top-1]].left = index;
                }
                else{
                    T[stack[top-1]].right = index;
                }
                // 该节点放入栈中，同时存入T中
                stack[top] = temp_data - '0' - 1;
                T[index].data = temp_data - '0';
                index++;
            }
            top++;
        }
        //出栈
        else if(strcmp(buffer, "Pop") == 0){
            top--;
            change_to_left_branch = 0;
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