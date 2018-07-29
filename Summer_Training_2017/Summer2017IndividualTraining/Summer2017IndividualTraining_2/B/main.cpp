#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 1010
#define INF 0x3f3f3f3f
#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

string a[MAXN];
string b[MAXN];
int n, m;
int main()
{
    #ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            cin>>a[i];
        for(int i=1; i<=m; i++)
            cin>>b[i];
        int cnt = 0;

         for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(a[i] == b[j])
                    cnt++;
        if(cnt & 1)
        {
            if(n > m - 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if(n > m)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}











