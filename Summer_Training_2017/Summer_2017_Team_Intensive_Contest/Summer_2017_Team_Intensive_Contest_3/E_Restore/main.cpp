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
#define MAXN 110
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
#define ReadInt(x) scanf("%I64d", &x)
typedef long long LL;

using namespace std;

LL num[MAXN][MAXN];
LL sum[MAXN];
LL he;
LL n;

int main()
{
    ReadInt(n);
    memset(num, 0, sizeof(num));
    memset(sum, 0, sizeof(sum));


    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            ReadInt(num[i][j]);
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(i != j)
            {
                sum[i]+=num[i][j];
                he += num[i][j];
            }
        }
    he /= (n-1);
    for(int i=0; i<n; i++)
        num[i][i] = he - sum[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%I64d%c", num[i][j], j==n-1?10:32);
    }
    return 0;
}









