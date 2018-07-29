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
//#define DEBUG
#define DataIn

typedef long long LL;

using namespace std;

int n,m;
int d[MAXN][MAXN];

int main()
{
    #ifdef DataIn
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int u,v;
        int flag = 1;

        memset(d, 0, sizeof(d));

        scanf("%d%d", &n, &m);

//        for(int i=1; i<=n; i++)
//            for(int j=1; j<=n; j++)
//                d[i][j] = INF;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&u, &v);
            d[u][v] = 1;
        }

        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    if(d[i][j] || (d[i][k]&&d[k][j]))
                    {
                        d[i][j] = 1;
                        break;
                    }

        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(!d[i][j] && !d[j][i])
                {
                    flag = 0;
                    break;
                }
            }

            if(flag == 0)
                break;
        }

        if(flag)
            puts("I love you my love and our love save us!");
        else
            puts("Light my fire!");
    }

    return 0;
}














