#include <cstdio>

//函数功能：传入一个正整数，若为奇数，返回true， 若为偶数，返回false

bool isOdd(int x)
{
    if(x&1)
        return true;
    else
        return false;
}

int main()
{
    int a;
    scanf("%d", &a);
    if(a&1)
        printf("Odd");
    else
        printf("Even");
    return 0;
}

//3958
