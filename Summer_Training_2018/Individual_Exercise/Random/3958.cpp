#include <cstdio>

//�������ܣ�����һ������������Ϊ����������true�� ��Ϊż��������false

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
