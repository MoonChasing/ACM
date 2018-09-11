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

int a[MAXN];

int main()
{
    int n, x;
    scanf("%d", &n);
    int ans = 0;
    int cnt = 0;
    a[0] = 0;
    scanf("%d", a);
    cnt = 1;
    for(int i=1; i<n; i++)
    {
        scanf("%d", x);
        if(x > a[cnt-1])
            a[cnt++] = x;
    }

    for(int i=0; i<cnt; i++)
        printf("%d ", a[i]);
    return 0;
}










