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
#define MAXN 205
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;
int n;
int a[MAXN][MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);

        if(n % 2 == 0)
        {
            puts("possible");
            for(int i=1; i<=n/2; i++)
            {
                for(int j=1; j<=n+1-i; j++)
                    a[i][j] = -1;
                for(int j=n-i+2; j<=n; j++)
                    a[i][j] = 0;
            }
            for(int i=n/2+1; i<=n; i++)
            {
                for(int j=i; j>=1; j--)
                    a[i][j] = 0;
                for(int j=n-i+2; j<=n; j++)
                    a[i][j] = 1;
            }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    printf("%3d%c", a[i][j], " \n"[j==n]);
                }
            }
        }
        else
            puts("impossible");
    }
}









