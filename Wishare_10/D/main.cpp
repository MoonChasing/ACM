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

int n;
int a[MAXN];
priority_queue<int, vector<int>, greater<int> > que;

int main()
{
    scanf("%d", &n);
    a[0] = 0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", a+i);
    }
    int ans = n;
    if(a[1] > a[2])
        que.push(a[1]);
    for(int i=2; i<n; i++)
    {
        if(a[i] > a[i-1] && a[i] > a[i+1])
            que.push(a[i]);
    }
    if(a[n] > a[n-1])
        que.push(a[n]);
    int n=1;
    int t;
    int pre;
    if(!que.empty())
    {
        pre = que.top();
        que.pop();
        ans += n;
    }
    while(!que.empty())
    {
        t = que.top();
        que.pop();
        if(t > pre)
            n++;
        ans += n;
        pre = t;
    }
    cout << ans << endl;
    return 0;
}







