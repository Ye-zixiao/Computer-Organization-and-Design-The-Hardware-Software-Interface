//StackFrame.c
/*---------这个程序对应了x86体系当中，过程调用时使用的栈帧数据成员的分布---------*/
/*--------x86一个栈帧的分布（从高地址到低地址）为：
        1、调用者的原帧基指针地址
        2、被调过程的局部变量块
        3、为被调过程中内嵌的过程准备的参数列表
        4、该被调函数的返回地址
----------
----------当然在这个程序中我们看到的是这样的分布：
            调用者栈帧的后半部分：
                                调用者局部变量区
                                给被调函数的参数列表（形参）
                                调用者返回地址
            被调函数的栈帧：
                                调用者的原帧基指针地址
                                被调函数的局部变量区
                                （因为被调函数是叶过程，所以不会有参数列表等出现）
---------一个有趣的现象：
                    局部变量区中，一般先定义的变量会占据高地址，
                    而后定义的变量会占据低地址内存块，但是对于数组/结构体
                    这些数据结构一般下标小的会占用低地址内存单元，而下标大
                    的会占据高地址内存单元，这也使得在使用数组时用下标索引
                    递增的方式可以依次访问数组的成员*/
#include <stdio.h>
#include <string.h>

struct Strt{
    int member1;
    int member2;
    int member3;
};

#define PRINT_ADDR(x)     printf("&"#x" = %p\n", &x)
int StackFrameContent(int para1, int para2, int para3){
    int locVar1 = 1;
    int locVar2 = 2;
    int locVar3 = 3;
    int arr[] = {0x11,0x22,0x33};
    struct Strt tStrt = {0};
    PRINT_ADDR(para1); //若para1为char或short型，则打印para1所对应的栈上整型临时变量地址！
    PRINT_ADDR(para2);
    PRINT_ADDR(para3);
    PRINT_ADDR(locVar1);
    PRINT_ADDR(locVar2);
    PRINT_ADDR(locVar3);
    PRINT_ADDR(arr);
    PRINT_ADDR(arr[0]);
    PRINT_ADDR(arr[1]);
    PRINT_ADDR(arr[2]);
    PRINT_ADDR(tStrt);
    PRINT_ADDR(tStrt.member1);
    PRINT_ADDR(tStrt.member2);
    PRINT_ADDR(tStrt.member3);
    return 0;
}

int main(void){
    int locMain1 = 1, locMain2 = 2, locMain3 = 3;
    PRINT_ADDR(locMain1);
    PRINT_ADDR(locMain2);
    PRINT_ADDR(locMain3);
    StackFrameContent(locMain1, locMain2, locMain3);
    printf("[locMain1,2,3] = [%d, %d, %d]\n", locMain1, locMain2, locMain3);
    memset(&locMain2, 0, 2*sizeof(int));
    printf("[locMain1,2,3] = [%d, %d, %d]\n", locMain1, locMain2, locMain3);
    return 0;
}
