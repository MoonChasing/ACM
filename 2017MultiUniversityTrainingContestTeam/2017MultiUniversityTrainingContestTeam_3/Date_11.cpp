//nupt2017team11

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
typedef long long LL;

using namespace std;
int n;
int tem[1000];
int main()
{
    int cnt=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",tem+i);
        if(tem[i] <= 35)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
