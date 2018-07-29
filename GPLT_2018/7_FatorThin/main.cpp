#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double EXP = 1E-6;
int judge(int h, int w)
{
    double bz = (h-100) * 1.8;
    double cha = w-bz;
    double exp = bz * 0.1;
    if(fabs(cha) < exp)
        return 0;
    else if(cha < 0)
        return -1;
    else
        return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int h,w;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &h, &w);
        int ans = judge(h,w);
        if(ans == 0)
            puts("You are wan mei!");
        else if(ans == -1)
            puts("You are tai shou le!");
        else
            puts("You are tai pang le!");
    }
    return 0;
}
