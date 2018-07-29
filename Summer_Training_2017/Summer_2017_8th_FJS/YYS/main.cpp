#include <iostream>
#include <cstdio>

using namespace std;

long long dp[3000];
void init()
{
    dp[0] = 1;
    for(int i=1; i<50; i++)
        dp[i] = dp[i-1] * i;
}

int main()
{
    init();
    int n = 9 ;
    long long sum = 0;
    for(int i=1; i<=n; i++)
    {
        sum += dp[n] / i;
    }
    printf("%lld.0\n",sum);
    return 0;
}
