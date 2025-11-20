#include<stdio.h>
#include<time.h>

int MaxSubseqSum_2(int A[], int len);
int MaxSubseqSum_4(int A[], int len);

    // clock_t为clock()函数的返回数据类型
    clock_t start, stop; // 声明两个变量用于计算程序运行时间

    double duration;     // 用于计算程序运行的时间，秒为单位

    #define TIME 1
/* 后续测试模板 */
    int main(){


    /* 函数运行前计数 */
    start = clock();


    /* 执行函数前的预处理 */
    int loop_time = 0;
    int MaxSum, len;
 
    // 创建数组并初始化
    printf("请输入数组长度：\n");
    scanf("%d", &len);
    int A[len];
    for(int i = 0; i < len; i++){
        scanf(" %d", &A[i]);
    }
    



    /* 函数体 */
    for(loop_time = 0; loop_time < TIME; loop_time++)
        MaxSum = MaxSubseqSum_4(A, len);
        printf("%d\n", MaxSum);







    /* 函数运行后计数 */
    stop = clock();
    duration = (double)(stop - start)/CLK_TCK;
    
    printf("程序运行 %d 遍\n", TIME);
    printf("CLK_TCK次数:%d\n", stop-start);
    printf("%d CLK_TCK/秒\n", CLK_TCK);
    printf("本测试一共运行 %f 秒\n", duration);

    return 0;
}


int MaxSubseqSum_2(int A[], int len){
    int left_boundary = 0;
    int right_boundary = 0;
    int cnt = 0;
    int sum = 0;
    int MaxSum = 0;

    for(left_boundary = 0; left_boundary < len; left_boundary++){
        sum = 0;
        for(right_boundary = left_boundary; right_boundary < len; right_boundary++){
            sum += A[right_boundary];
            
            if(sum > MaxSum)
                MaxSum = sum;

        }
    }

    return MaxSum;
}

int MaxSubseqSum_4(int A[], int len){
    int ThisSum, MaxSum;
    ThisSum = MaxSum = 0;

    for(int i = 0; i < len; i++){
        ThisSum += A[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
        
    }
    return MaxSum;
}