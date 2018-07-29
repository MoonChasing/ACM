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
#define MAXN 110
#define INF 0x3f3f3f3f
#define ReadInt(x) scanf("%d", &x)
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n;
int ans;
int len;
int cnt;
int cika[MAXN];
char words[MAXN];
char cube[MAXN][10];
bool vis[MAXN];


void dfs()
{
    if(ans == len)
        return;

    for(int i=1; i<=n; i++)
    {
        if(vis[i] == true)
            continue;
        for(int j=1; j<=6; j++)
        {
            if(cube[i][j] == words[ans+1])
            {
                ans++;
                vis[i] = true;
                if(ans == len)
                    return;
                dfs();
                if(ans == len)
                    return;
                ans--;
                vis[i] = false;
                break;
            }

        }
    }
}
int main()
{
//    #ifdef DataIn
//	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
//    #endif
    scanf("%s", words+1);
    len = strlen(words+1);
    ReadInt(n);
    getchar();
    memset(vis, false, sizeof(vis));
    ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=6; j++)
        {
            scanf("%c", &cube[i][j]);
            getchar();
            if(cube[i][j] == words[1])
            {
                cnt++;
                cika[cnt] = i;
            }
        }

    for(int i=1; i<=cnt; i++)
    {
        vis[cika[i]] = true;
        ans = 1;
        dfs();
        if(len == ans)
        {
            puts("YES");
            return 0;
        }
        vis[cika[i]]= false;
        ans = 0;
    }
    puts("NO");
    return 0;
}



















