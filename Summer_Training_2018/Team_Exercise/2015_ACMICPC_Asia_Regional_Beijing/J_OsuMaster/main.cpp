#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        getchar();
        int ans=0,a;
        char c;
        for(int i=1;i<=n;i++)
        {
            c = getchar();
            getchar();
            if(c=='S')
              ans++;
            else
            {
                scanf("%d", &a);
                getchar();
                if(a==1)
                  ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
