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
#define MAXN 65
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int stick[MAXN];
bool used[MAXN];
int n;
int tarnum, tarlen;
bool ok = false;

void dfs(int curnum, int curlen, int ind)
{
    if(ok || curnum == tarnum)
    {
        ok = true;
        return;
    }

    for(int i=ind; i<n; i++)
    {
        if(used[i] || curlen + stick[i] > tarlen)
            continue;
        if(i-1>0 && !used[i-1] && stick[i] == stick[i-1])
            continue;

        if(stick[i] + curlen == tarlen)
        {
            used[i] = true;
            dfs(curnum+1, 0, 0);
            used[i] = false;
            return;
        }
        if(stick[i] + curlen < tarlen)
        {
            used[i] = true;
            dfs(curnum, stick[i] + curlen, ind+1);
            used[i] = false;
            if(curlen == 0)
                return;

        }
    }
}
int main()
{
    while(~scanf("%d", &n) && n)
    {
        int sum = 0;
        memset(used, false, sizeof(used));
        ok = false;

        for(int i=0; i<n; i++)
        {
            scanf("%d", stick+i);
            sum += stick[i];

        }

        sort(stick, stick+n, greater<int>());

        for(tarnum=n; tarnum>=1; tarnum--)
        {
            if(sum % tarnum || stick[0] > sum/tarnum);
                continue;
            tarlen = sum / tarnum;

            dfs(0,0,0);

            if(ok)
                break;
        }
        printf("%d\n", tarlen);
    }

    return 0;
}









