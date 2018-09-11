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
#define MAXN 100010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

LL tmp;
LL bfs(int n)
{
    queue<LL> que;
    que.push(1);
    while(!que.empty())
    {
        tmp = que.front();
        que.pop();
        if(tmp % n == 0)
            return tmp;
        que.push(tmp*10);
        que.push(tmp*10+1);
    }
    return 0;
}
int main()
{
    int n;
    LL ans;
    while(scanf("%d", &n) && n)
    {
        ans = bfs(n);
        printf("%lld\n", ans);
    }
    return 0;
}
