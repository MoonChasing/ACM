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
#define offset 1000
#define eps 1e-8
//浮点数判断符
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
//浮点数判0
#define zero(x) (((x)>0?(x):-(x))<eps)
typedef long long LL;

using namespace std;

struct point
{
    int x,y;
} pt[MAXN];

double xmult(point p1, point p2, point p0)
{
    return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y-p0.y);
}

int isConvex(int n, point* p)
{
    int s[3] ={1,1,1};
    for(int i=0; i<n&&s[1]|s[2]; i++)
        s[_sign( xmult( p[(i+1)%n], p[(i+2)%n], p[i]))] = 0;
    return s[1]|s[2];
}

int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n; i++)
            scanf("%d%d",&pt[i].x, &pt[i].y);
        printf("%s\n",isConvex(n, pt)?"convex":"concave");
    }
    return 0;
}
