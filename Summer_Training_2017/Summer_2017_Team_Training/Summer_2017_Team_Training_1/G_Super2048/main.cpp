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
#define MAXN 25
#define INF 0x3f3f3f3f
#define scanfint(x) scanf("%d", &(x))
typedef long long LL;

using namespace std;

int a[MAXN][MAXN];
char oper[10];
int n;

void solve()
{
    int nextj;

    if(oper[0] == 'r')
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=n; j>=1; j=nextj)
            {
                nextj = j-1;
                if(a[i][j] != 0)
                {
                    for(int k=j-1; k>=1; k--)
                    {
                        if(a[i][k] == 0)
                        {
                            nextj = k;
                            continue;
                        }
                        else if(a[i][j] != a[i][k])
                        {
                            nextj = k;
                            break;
                        }
                        else if(a[i][j] == a[i][k])
                        {
                            nextj = k-1;
                            a[i][j] *= 2;
                            a[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }

        vector<int> b;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i][j] != 0)
                    b.push_back(a[i][j]);
            }
            int numnotzero = b.size();
            int numzero = n-numnotzero;
            for(int j=1; j<=numzero; j++)
                a[i][j] = 0;
            for(int j=numzero+1; j<=n; j++)
                for(int k=0; k<numnotzero; k++)
                    a[i][j] = b[k];
            b.clear();
        }

    }
    else if(oper[0] == 'l')
    {

    }
    else if(oper[0] == 'u')
    {

    }
    else if(oper[0] == 'd')
    {

    }
}
int main()
{
    int T;
    scanfint(T);
    while(T--)
    {
        scanfint(n);
        getchar();
        gets(oper);
        memset(a, 0, sizeof(a));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanfint(a[i][j]);

        solve();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                printf("%d ",a[i][j]);
            putchar(10);
        }
    }
    return 0;
}
