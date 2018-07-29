#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t,len,q=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&len);
        int sum=0;
        while(len!=0)
        {
            sum++;
            len/=2;
        }
        printf("Case %d: %d\n",q++,sum);
    }
    return 0;
}
