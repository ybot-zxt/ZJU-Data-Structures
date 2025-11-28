#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 1005

int main(){
    
    // 步骤一：获得MNK并初始化栈和数列
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    int flag = 1;
    int top = -1;
    int current_tobe_push = 1;
    int stack[MAXLEN];
    int target;


    // 步骤二遍历每一行pop sequence
    while(K--){
        flag = 1;
        top = -1;
        current_tobe_push = 1;


        // 步骤二.1:遍历每一个pop sequence里面的数字
        for(int i = 0; i < N; i++){
            scanf(" %d", &target);

            if(flag == 0) continue;

            if((top != -1) && stack[top] == target){
                top--;
            }
            else if((top == -1) || stack[top] < target){    // 栈里没东西或者有但是小，那就尝试压栈
                while(current_tobe_push <= target){
                    if(current_tobe_push > N || top +1 >= M){
                        flag = 0;
                        break;
                    }
                    else
                        stack[++top] = current_tobe_push++;

                }
                if( (flag == 1) && (stack[top] == target)){
                    top--;
                }
                else
                    flag = 0;
            }
            else
                flag = 0;
        }

        // 步骤二.2：判断YES NO
        if(flag) printf("YES\n");
        else printf("NO\n");

    }

    return 0;
}