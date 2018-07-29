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
    int T;
    scanf("%d", &T);
    int a,b,c;
    int ans;
    while(T--)
    {

        scanf("%d%d%d",&a, &b,&c);
        ans = min(a,b);
        ans = min(ans, c);
        if(ans == a)
            puts("First");
        else if(ans == b)
            puts("Second");
        else
            puts("Third");

    }
    return 0;
}










