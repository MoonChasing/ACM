#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 100010;

char s[MAXN];
int dp[MAXN][26];

int T, len, q;

int main()
{
    scanf("%d", &T);
    int l, r;
    for(int kiss = 1; kiss <= T; kiss++)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &len, &q);
        scanf("%s", s+1);
        for(int i=1; i<=len; i++)
        {
            for(int j=0; j<26; j++)
                dp[i][j] = dp[i-1][j];
            dp[i][s[i]-'A']++;
        }
        printf("Case #%d:\n", kiss);
        while(q--)
        {
            int ans = 0;
            scanf("%d%d", &l, &r);
            for(int i=0; i<26; i++)
            {
                if(dp[r][i] - dp[l-1][i])
                {
                    ans = dp[r][i] - dp[l-1][i];
                    break;
                }
            }
            printf("%d\n", ans);
        }

    }

    return 0;
}
