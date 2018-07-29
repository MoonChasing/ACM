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
#define MAXN 105
#define INF 0x3f3f3f3f
//#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int mar[MAXN][MAXN];
int num[10000];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n,m,q;
        scanf("%d%d%d", &n, &m, &q);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d", &mar[i][j]);
            }
        }

        int x1,y1,x2,y2;
        int cnt = 0;
        for(int i=0; i<q; i++)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            cnt = 0;
            for(int x=x1; x<=x2; x++)
                for(int y=y1; y<=y2; y++)
                {
                    num[cnt++] = mar[x][y];
                }
            //printf("%d\n", cnt);
            sort(num, num+cnt);
#ifdef DEBUG
            for(int i=0; i<cnt; i++)
                cout << num[i] << "  ";
#endif // DEBUG
            //int geshu = (x2-x1+1) * (y2-y1+1);
            printf("%d\n", num[cnt-1 >> 1]);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 100 + 3, M = 500 + 5;
int n, m, q, a, b, c, d, v[N][N], freq[N][N][M], f[M], sz;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &m, &q);
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
            {
                scanf("%d", &v[i][j]);
                for(int k=1; k<=500; ++k)
                    freq[i][j][k] = freq[i-1][j][k] + freq[i][j-1][k]
                                    - freq[i-1][j-1][k] + (v[i][j] == k);
            }
        while(q--)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            sz = (c-a+1)*(d-b+1) + 1;
            sz /= 2;
            for(int i=1; i<=500; ++i)
            {
                f[i] = freq[c][d][i] - freq[a-1][d][i]
                       - freq[c][b-1][i] + freq[a-1][b-1][i];
                if(f[i] == 0) continue;
                sz -= f[i];
                if(sz <= 0)
                {
                    sz = i;
                    break;
                }
            }
            printf("%d\n", sz);
        }
    }
    return 0;
}





