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
struct ed
{
    int u, v;
}edge[MAXN];

int main()
{
    int n=100;
    int totV = n, totE = 0;
    for(int i=1; i<=n; i++)
    {
        int cika = n/i;
        for(int j=1; j<=cika; j++)
        {
            totV++;
            for(int k=1; k<=i; k++)
            {
                edge[totE].u = totV;
                edge[totE++].v = (j-1)*i+k;
            }
        }
    }
    printf("%d %d\n", totV, totE);
    for(int i=0; i<totE; i++)
        printf("%d %d\n", edge[i].u, edge[i].v);
    printf("%d\n", n);
    for(int i=1; i<=n; i++)
        printf("%d\n", i);
    return 0;
}











