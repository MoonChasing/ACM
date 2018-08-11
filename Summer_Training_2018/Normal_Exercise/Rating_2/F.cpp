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

int main()
{
    int n;
    scanf("%d", &n);
    int a, b;
    int ans = 0;
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a);
        q.push(a);
    }
    while(q.size() != 1)
    {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        ans += a+b;
        q.push(a+b);
    }
    printf("%d\n", ans);
    return 0;
}












