#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
const double eps = 1e-8;
using namespace std;
typedef pair<int,int> P;
const int mod = 1e9 + 7;
//B15041628
typedef long long LL;
const int N = 1e6 + 5;

int a[27][N];
char str[N];
int len[27]; // 字母权值的长度
int vis[27];
int canzero[27];
int rate[27];
int n;

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    memset(len, 0, sizeof(len));
    for(int i = 0; i < 26; i++)
        canzero[i] = 1;
}
int cmp(int x, int lena, int y, int lenb)
{
    if(lena > lenb)
        return 1;
    if(lena < lenb)
        return -1;
    for(int i = lena; i >= 0; i--)
    {
        if(a[x][i] > a[y][i])
            return 1;
        else if(a[x][i] < a[y][i])
            return -1;
    }
    return 0;
}


int main()
{
    int kase = 0;
    while(EOF != scanf("%d", &n))
    {
        init();
        for(int i = 0; i < n; i++)
        {
            scanf("%s", str);
            int length = strlen(str);
            if(length > 1) canzero[str[0]-'a'] = 0;
            for(int j = length - 1, k = 0; j >= 0; j--, k++)
            {
                int v = str[j] - 'a';
                len[v] = max(len[v], k+1);
                a[v][k]++;
            }
        }

        for(int i = 0; i < 26; i++)
        {
            int j = 0;
            while(a[i][j] != 0 || j < len[i])
            {
                int tmp = a[i][j] / 26;
                a[i][j] %= 26;
                a[i][j+1] += tmp;
                j++;
            }
            len[i] = j;
        }

        LL ans = 0, weight = 25;
        int cnt = 0;
        while(true)
        {
            int index = -1;
            for(int i = 0; i < 26; i++)
            {
                if(vis[i] || len[i] == 0) continue;
                if(index == -1 || cmp(index,len[index], i, len[i]) <= 0)
                {
                    index = i;
                }
            }
            if(index == -1) break;
            vis[index] = 1;
            rate[cnt++] = index;
            if(weight == 0)
            {
                for(int p = cnt -1; p >= 0; p--)
                {
                    if(canzero[rate[p]])
                    {
                        int tmp = rate[p];
                        for(int q = p; q < cnt - 1; q++)
                            rate[q] = rate[q+1];
                        rate[cnt-1] = tmp;
                        break;
                    }
                }
            }
            weight--;

        for(int i = 0; i < cnt; i++)
        {
            LL tmp = 0;
            for(int j = len[rate[i]] - 1; j >= 0; j--)
            {
                tmp = (tmp*26)%mod + a[rate[i]][j];
                tmp %= mod;
            }
            ans = ((tmp*(25-i))%mod + ans) % mod;
        }

        printf("Case #%d: %I64d\n", ++kase, ans%mod);
    }
    return 0;
}
