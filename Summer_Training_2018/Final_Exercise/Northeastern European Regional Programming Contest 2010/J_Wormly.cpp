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
#define MAXN  1000010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int L, b, n;
char ch[MAXN];
int ok[MAXN], dp[MAXN];

LL solve()
{
    int op=0, m = 0;
    for(int i=0; i<n; i++)
        if(ch[i] == '1')
            ok[m++] = i;
    dp[L-1] = 0;
    for(int i=L; i<n; i++)
        dp[i] = ch[i]=='1' ? ok[++op] : dp[i-1];

    LL ans = 0LL;
    int lastLeg = 0, head = b-1, tail = 0, res = 1;

    while(1)
    {
        int pos = dp[head];
        if(pos == lastLeg)
            res = 0;
        if(!res)
            break;

        lastLeg = pos;
        ans += L;
        if(lastLeg+b-1 >=n)
        {
            ans += n-b-tail;
            tail = n-b;
        }
        else
        {
            ans += lastLeg-tail;
            tail = lastLeg;
        }
        head = tail+b-1;
    }
    if(head == n-1)
        return ans;
    else
        return -1LL;
}

int main()
{
    int T;
    scanf("%d", &T);
    LL ans = 0;
    while(T--)
    {
        scanf("%d%d%d%s", &L, &b, &n, ch);
        LL ans = solve();

        if(~ans)
            printf("%lld\n", ans);
        else
            puts("IMPOSSIBLE");

    }
    return 0;
}












