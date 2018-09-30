#include <bits/stdc++.h>
using namespace std;
const int MAXX=100000+5;
const int INF=0x7fffffff;

int a[MAXX],dp[MAXX];

//首先输入数字个数n， 之后输入n个数字
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            dp[i]=INF;
        }
        int pos=0;
        dp[0]=a[0];
        for(int i=1; i<n; i++)
        {
            if(a[i]>dp[pos])
                dp[++pos] = a[i];
            else
                dp[lower_bound(dp,dp+pos+1,a[i])-dp]=a[i];
        }
        cout<<pos+1<<endl;
    }
    return 0;
}

//3167
