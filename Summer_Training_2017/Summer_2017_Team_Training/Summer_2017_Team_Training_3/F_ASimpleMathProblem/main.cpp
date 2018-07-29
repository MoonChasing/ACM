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
#define LOCAL
typedef long long LL;

using namespace std;
int dp[MAXN];
int a[10] = {1, 0, 1,0,1,0,1,0,1,0};
void init(int mod)
{
    memset(dp, 0 ,sizeof(dp));
    for(int i=0; i<10; i++)
    {
        dp[i] = i;
    }
    for(int i=10; i<=100; i++)
        for(int j=0; j<=9; j++)
            dp[i] = (dp[i] + a[j] * dp[i-j-1]) % mod;
}
int main()
{
//    #ifdef LOCAL
//        fropen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
//    #endif
    #ifdef DEBUG
    init(500);
    int cnt=0;
    for(int i=0; i<=100; i++)
    {
        printf("%d  ",dp[i]);
        cnt++;
        if(cnt %10 == 0)
            putchar(10);
    }
    #endif // DEBUG
}










