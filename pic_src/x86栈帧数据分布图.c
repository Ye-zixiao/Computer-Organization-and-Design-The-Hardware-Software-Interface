//StackFrame.c
/*---------��������Ӧ��x86��ϵ���У����̵���ʱʹ�õ�ջ֡���ݳ�Ա�ķֲ�---------*/
/*--------x86һ��ջ֡�ķֲ����Ӹߵ�ַ���͵�ַ��Ϊ��
        1�������ߵ�ԭ֡��ָ���ַ
        2���������̵ľֲ�������
        3��Ϊ������������Ƕ�Ĺ���׼���Ĳ����б�
        4���ñ��������ķ��ص�ַ
----------
----------��Ȼ��������������ǿ������������ķֲ���
            ������ջ֡�ĺ�벿�֣�
                                �����߾ֲ�������
                                �����������Ĳ����б��βΣ�
                                �����߷��ص�ַ
            ����������ջ֡��
                                �����ߵ�ԭ֡��ָ���ַ
                                ���������ľֲ�������
                                ����Ϊ����������Ҷ���̣����Բ����в����б�ȳ��֣�
---------һ����Ȥ������
                    �ֲ��������У�һ���ȶ���ı�����ռ�ݸߵ�ַ��
                    ������ı�����ռ�ݵ͵�ַ�ڴ�飬���Ƕ�������/�ṹ��
                    ��Щ���ݽṹһ���±�С�Ļ�ռ�õ͵�ַ�ڴ浥Ԫ�����±��
                    �Ļ�ռ�ݸߵ�ַ�ڴ浥Ԫ����Ҳʹ����ʹ������ʱ���±�����
                    �����ķ�ʽ�������η�������ĳ�Ա*/
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
    PRINT_ADDR(para1); //��para1Ϊchar��short�ͣ����ӡpara1����Ӧ��ջ��������ʱ������ַ��
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
