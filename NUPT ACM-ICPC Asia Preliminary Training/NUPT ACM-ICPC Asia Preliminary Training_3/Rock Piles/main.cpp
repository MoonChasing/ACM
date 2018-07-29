#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n, &m);
        if((n&1) || (m&1))
            puts("hasan");
        else
            puts("abdullah");
    }
    return 0;
}
