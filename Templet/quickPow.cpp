#include<stdio.h>

int quickPow(int x, int y)
{
    int ans = 1;
    while(y)
    {
        if(y&1)
            ans *= x;
        x*=x;
        y>>=1;
    }
    return ans;
}
//
//int quickPowMod(int x, int y)
//{
//    int ans = 1;
//    while(y)
//    {
//        if(y&1)
//            ans = ans * x %MOD;
//        x = x*x%MOD;
//        y>>=2;
//    }
//    return ans;
//}
int quickPow(int a, int b)
{
    int ans =1;
    while(b)
    {
        if(a&1)
            ans *= a;
        a*=a;
        b>>=1;
    }
    return ans;
}
int main()
{
    int c = quickPow(3,5);
    printf("%d", c);
    return 0;
}
