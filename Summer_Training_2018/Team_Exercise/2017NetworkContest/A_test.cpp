#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int INF=0x3f3f3f3f,maxn=100001;
int main()
{
    int n=15,m=0;
    for(int i=1;i<=n;i++)m+=n/i*i;
    printf("%d %d\n",4*n,m);
    int res=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n/i;j++)
            for(int k=1;k<=i;k++)
                printf("%d %d\n",(j-1)*i+k,res+j);
        res+=n/i;
    }
    printf("%d\n",n);
    for(int i=1;i<=n;i++)printf("%d\n",i);
    return 0;
}
