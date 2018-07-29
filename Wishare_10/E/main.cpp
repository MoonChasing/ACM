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

int dp[105][105];
int main()
{
    int lena, lenb;
    cin >> lena >> lenb;

    string a,b;
    cin>>a>>b;
    int len = max(lena, lenb);

    for(int i=0; i<=len; ++i)
        dp[i][0]=dp[0][i]=0;
    for(int i=0; i<lena; i++)
    {
        for(int j=0; j<lenb; j++)
        {
            if(a[i] == b[j])
                dp[i+1][j+1] = dp[i][j]+1;
            else
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    for(int i=1; i<=7; i++)
    {
        for(int j=1; j<=7; j++)
            printf("%-4d", dp[i][j]);
        putchar(10);
    }

    return 0;
}









