#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int MOD = 1e9+7;
int dp[100010];
void init()
{
    memset(dp, 0 , sizeof(dp));
    dp[0] = 1;
    int flag = 1;
    for(int i=1; i<=100000; i++)
    {
        for(int j=1; ; j++)
        {
            int exp1 = i-(3*j*j-j)/2;
            int exp2 = i-(3*j*j+j)/2;

            if(j&1)
                flag = 1;
            else
                flag = -1;

            if(exp1<0)
                break;

            dp[i] += dp[exp1] * flag;
            dp[i] %= MOD;
            dp[i] = (dp[i]+MOD)%MOD;
            if(exp2 >= 0)
            {
                dp[i] += (dp[exp2] * flag);
                dp[i] %= MOD;
                dp[i] = (dp[i]+MOD)%MOD;
            }

        }
    }
}
int main()
{
    int T;
    int n;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
