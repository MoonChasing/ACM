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

point she[1000];
double xmult(point p1, point p2, point p0)
{
    return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y-p0.y);
}

//判点在凸多边形内或多边形边上时返回 1，严格在凸多边形外返回0
int inside_convex(point q,int n, point* p)
{
    int i,s[3]= {1,1,1};
    for (i=0; i<n&&s[1]|s[2]; i++)
        s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
    return s[1]|s[2];
}

//判点严格在凸多边形内返回 1,在边上或者严格在外返回0
int inside_convex_v2(point q, int n, point *p)
{
    int i, s[3]= {1,1,1};
    for(i=0; i<n && s[0] && s[1]|s[2]; i++)
        s[_sign( xmult( p[(i+1)%n], q, p[i]))]=0;
    return s[0]&&s[1]|s[2];
}

int inside_polygon(point q,int n,point* p,int on_edge=2)
{
    point q2;
    int i=0,cnt;
    while (i<n)
        for (cnt=i=0,q2.x=rand()+offset,q2.y=rand()+offset; i<n; i++)
        {
            if (zero(xmult(q,p[i],p[(i+1)%n]))&&(p[i].x-q.x)*(p[(i+1)%n].x-q.x)<eps
                    &&(p[i].y-q.y)*(p[(i+1)%n].y-q.y)<eps)
                return on_edge;
            else if (zero(xmult(q,q2,p[i])))
                break;
            else if (xmult(q,p[i],q2)*xmult(q,p[(i+1)%n],q2)<-eps&&
                     xmult(p[i],q,p[(i+1)%n])*xmult(p[i],q2,p[(i+1)%n])<-eps)
                cnt++;
        }
    return cnt&1;
}

int main()
{
    int N;
    while(~scanf("%d",&N))
    {
        for(int i=0; i<N; i++)
            scanf("%d%d",&pt[i].x, &pt[i].y);
        int M;
        scanf("%d",&M);
        for(int i=0; i<M; i++)
        {
            scanf("%d%d", &she[i].x, &she[i].y);
            printf("%s\n",inside_polygon(she[i], N, pt)?"Yes":"No");
        }

    }
    return 0;
}
