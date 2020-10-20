#include "stdio.h"

int max(int x, int y)
{
    return ( x>y ? x : y );
}

void main()
{
    int (*pfunc) (int, int); //函数指针的声明
    pfunc = max; //函数指针的初始化
    printf("the maximum is: %d \n", max(10, 5));
    printf("the maximum is: %d \n", pfunc(10, 5)); //函数指针的使用
    printf("the maximum is: %d \n", (*pfunc)(10, 5)); //函数指针的使用
}

//https://www.cnblogs.com/JCSU/articles/1088831.html