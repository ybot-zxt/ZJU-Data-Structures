#include<stdio.h>
#include<time.h>

    // clock_t为clock()函数的返回数据类型
    clock_t start, stop; // 声明两个变量用于计算程序运行时间

    double duration;     // 用于计算程序运行的时间，秒为单位

/* 后续测试模板 */
    int main(){


    /* 函数运行前计数 */
    start = clock();


    /* 执行函数前的预处理 */
    int loop_time = 0;


    /* 函数体 */
    for(loop_time = 0; loop_time < 10000; loop_time++)
        printf("Hello, world!\n");


    /* 函数运行后计数 */
    stop = clock();
    duration = (double)(stop - start)/CLK_TCK;
    
    printf("程序运行 %d 遍\n", loop_time);
    printf("CLK_TCK次数:%d\n", stop-start);
    printf("%d CLK_TCK/秒\n", CLK_TCK);
    printf("本测试一共运行 %f 秒\n", duration);

    return 0;
}