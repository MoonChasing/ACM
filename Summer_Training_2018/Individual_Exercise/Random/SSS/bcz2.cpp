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
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int a[MAXN];
int n, k;
bool dfs(int i, int sum)
{
    if(i==n)
        return sum == k;

    if(dfs(i+1, sum))
        return true;
    if(dfs(i+1, sum+a[i]))
        return true;
    return false;
}
int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    scanf("%d", &k);
    if(dfs(0,0))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}











