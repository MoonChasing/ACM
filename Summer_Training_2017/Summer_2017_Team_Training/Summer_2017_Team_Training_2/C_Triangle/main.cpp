#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LL long long
const int maxn = 20;
LL a[maxn];
bool used[maxn];
int n;

using namespace std;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(used, false, sizeof(used));
        for(int i=0; i<n; i++)
            scanf("%I64d", a+i);
        sort(a,a+n);
        int ans=0;
        for(int i=0; i<n-2; i++)
        {
            if( used[i] == true )
                continue;
            for(int j=i+1; j<n-1; j++)
            {
                if(used[j] == true)
                    continue;
                if(used[i] == true)
                    break;
                for(int k=j+1; k<n; k++)
                {
                    if( used[k] == true )
                        continue;
                    if( used[i] == true )
                        break;
                    if( used[j] == true)
                        break;
                    if( a[i]+a[j]>a[k] )
                    {
                        ans++;
                        used[i] = true;
                        used[j] = true;
                        used[k] = true;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
