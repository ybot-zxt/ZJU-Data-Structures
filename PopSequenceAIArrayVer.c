// AI版
#include <stdio.h>
#include <stdlib.h>


#define MAX_N 1005

int main() {
    int M, N, K; 
    scanf("%d %d %d", &M, &N, &K);

    int stack[MAX_N]; 
    int top = -1;     

    while (K--) {
        // 步骤一：初始化栈，flag和push的数列
        top = -1;          // 把top放在NULL的位置上
        int current_push = 1; // 初始化push的数列
        int flag = 1;       // 开始遍历一列前flag 设为true
        
        // 步骤二：遍历每一列的每一个数，进行判断
        for (int i = 0; i < N; i++) {
            // 储存输入
            int target;
            scanf("%d", &target); 

            // 还没有判断这个target时flag已经是0，跳过循环，不操作栈
            if (flag == 0) continue; 


            // 只要栈的top不是target，就不能pop,就需要进入循环尝试压栈
            while (top == -1 || stack[top] != target) {
                // 看看能不能压进去
                if (current_push > N || top + 1 >= M) { // 压栈有两个阻碍，一个是栈，一个是压的数。栈要有空间，所以top + 1 < M.输入的数不能大于N，换言之curr_push数最大到N,哪怕有空间，还没找到target也不能再压栈了。
                    flag = 0;
                    break; 
                }

                stack[++top] = current_push++;
            }

            // 刚刚判断出来的flag == 0就直接continue
            if (flag == 1) {

                if (top != -1 && stack[top] == target) {
                    top--; 
                } else {
                    flag = 0; 
                }
            }
        }

        // 判断YES NO
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}