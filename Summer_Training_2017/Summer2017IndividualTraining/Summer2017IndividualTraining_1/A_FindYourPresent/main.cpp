#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n) && n)
    {
        int ans = 0;
        int num;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num);
            ans ^= num;
        }
        printf("%d\n",ans);
    }
    return 0;
}
