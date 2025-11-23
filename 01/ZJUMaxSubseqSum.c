#include<stdio.h>
#include<time.h>

int ZJUMaxSubseqSum(int A[], int , int *, int *);

    // clock_t为clock()函数的返回数据类型
    clock_t start, stop; // 声明两个变量用于计算程序运行时间

    double duration;     // 用于计算程序运行的时间，秒为单位

    #define TIME 1
/* 后续测试模板 */
    int main(){


    /* 执行函数前的预处理 */
    int loop_time = 0;
    int MaxSum, len;
    int FirstNum, LastNum;
    FirstNum = LastNum = 0;
 
    // 创建数组并初始化
    scanf("%d", &len);
    int A[len];
    for(int i = 0; i < len; i++){
        scanf(" %d", &A[i]);
    }
    
    /* 函数运行前计数 */
    start = clock();


    /* 函数体 */
    for(loop_time = 0; loop_time < TIME; loop_time++)
        MaxSum = ZJUMaxSubseqSum(A, len, &FirstNum, &LastNum);

    printf("%d %d %d\n", MaxSum, FirstNum, LastNum);







    /* 函数运行后计数 
    stop = clock();
    duration = (double)(stop - start)/CLK_TCK;
    
    printf("程序运行 %d 遍\n", TIME);
    printf("CLK_TCK次数:%d\n", stop-start);
    printf("%d CLK_TCK/秒\n", CLK_TCK);
    printf("本测试一共运行 %f 秒\n", duration);  */

    return 0;
}



int ZJUMaxSubseqSum(int A[], int len, int * FirstNum, int * LastNum){
    int ThisSum, MaxSum;
    ThisSum = 0;
    MaxSum = -1;                            // MaxSum 是负数时才返回0，所以如果MaxSum计算得是0（子列只有负数和0，MaxSum就是0那一项），应该返回0的位置，而不是A[0]和A[len-1]因此将MaxSum初始值设为负数
    *FirstNum = A[0];
    *LastNum = A[0];
    int temp_first_index;
    temp_first_index = 0;

    for(int i = 0; i < len; i++){
        ThisSum += A[i];
        if(ThisSum > MaxSum){
            MaxSum = ThisSum;
            *FirstNum = A[temp_first_index];
            *LastNum = A[i];
        }

        else if(ThisSum < 0){
            temp_first_index = i + 1;
            ThisSum = 0;
        }

    }

    if(MaxSum < 0){                     // 只在整个子列全部是负数的情况下执行if，只有此时最大值是负数
        *LastNum = A[len-1];
        return 0;
    }
    return MaxSum;
}