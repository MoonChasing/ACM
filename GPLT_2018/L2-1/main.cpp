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


int sfid[MAXN];
double gongli[MAXN];
vector<int>  E[MAXN];

int n;
double z, r;
double ans;

int main()
{
    memset(sfid, -1, sizeof(sfid));
    cin >> n >> z >> r;
    r = (100.0-r) / 100;
    int num, bh;

    gongli[0] = z;
    ans = 0;
    int times;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        if(!num)
        {
            scanf("%d", &times);
            gongli[i] = gongli[sfid[i]] * r *times;
            ans += gongli[i];
        }

        for(int j = 1; j<=num; j++)
        {
            scanf("%d", &bh);
            sfid[bh] = i;
            gongli[bh] = gongli[i] * r;
        }
    }
    printf("%.0f\n",  ans-0.5);
    return 0;
}






