#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 5000007
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int a[MAXN];
int n , m;
bool cc(int num) //每个箱子最多放num个时够用吗
{
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        //cnt += (int)ceil((double)a[i] / num);
        if(a[i]%num==0)
            cnt+=a[i]/num;
        else
            cnt+=a[i]/num+1;
    }
    if(cnt > m)
        return false;
    else
        return true;
}

int main()
{
    while(scanf("%d%d", &n , &m) && (~n || ~m ) )
    {
        for(int i=0; i<n; i++)
            scanf("%d", a+i);

        int l=1, r=MAXN;
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(!cc(mid))
                l = mid+1;
            else
                r = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}











