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
int main()
{
    int n,m;
    int a,b;
    double price;
    double minn = INF;
    scanf("%d%d", &n, &m);
    for(int T=0; T<n; T++)
    {
        scanf("%d%d", &a, &b);
        price = a/(double)b;
        minn = min(minn, price);
    }
    printf("%f\n",minn*m);
    return 0;
}


