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
    int a[15];
    scanf("%d", &n);
    int minn = INF;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", a+i);
    }

    int height;
    scanf("%d", &height);
    for(int i=0; i<n; i++)
    {
        if(height % a[i] < minn)
            {ans = a[i];
            minn = height%a[i];}
    }
    printf("%d\n", ans);
    return 0;
}











