#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 55
#define INF 0x3f3f3f3f
//#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;
int n,m;
char ch;
int ans;
char str[10010];
char keyboard[MAXN][MAXN];
struct P
{
    int x, y;
    bool operator ==(const P & p1)
    {
        return (x == p1.x) && (y == p1.y);
    }
    bool operator != (const P & p1)
    {
        if(x == p1.x) && (y == p1.y)
            return false;
        else
            return true;
    }
};

multimap<char, P> key;
int keydist_1(P p1, P p2)
{
    int ans = 0;
    while(p1 != p2)
    {
        while(p1.x < p2.x)
        {
            ans++;

        }
    }
}

int solve()
{
    P now = {1,1};
    P to;
    P temp;
    int len = strlen(str);
    str[len++] = '*';
    str[len] = '\0';
    char chto;
    multimap<char, P>::iterator it;
    int sum = 0;
    for(int i=0; i<len; i++)
    {
        chto = str[i];
        int num = key.count(chto);
        int j;
        int mindist = INF;
        for(j=0, it = key.find(chto); j<num; j++, it++)
        {
            to = it->second;
            int d = dist(now, to);
            if(d < mindist)
            {
                mindist = d;
                temp = to;
            }
        }
            sum += mindist;
            sum++;
            now = temp;
    }
     return sum;
}


int main()
{
#ifdef DataIn
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
#endif
    while(~scanf("%d%d", &n, &m))
    {
        getchar();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                ch = getchar();
                keyboard[i][j] = ch;
                P p = {i,j};
                key.insert(make_pair(ch, p ) );
            }
            getchar();//读回车
        }
        gets(str);
        ans = solve();
        printf("%d\n",ans);
    }
}






            //特殊情况： 如果距离相等，要判断两者哪一个距下一个字符近
//            if(d == mindist)
//            {
//                char next = str[i+1];
//                P pnext;
//                int nextnum = key.count(next);
//                int k;
//                int prenext = INF, nownext = INF;
//                multimap<char, P>::iterator itnext;
//                for(k=0, itnext = key.find(next); k<nextnum; k++, itnext++)
//                {
//                    pnext = it->second;
//                    prenext = min(dist(temp, pnext), prenext);
//                    nownext = min(dist(to, pnext), nownext);
//                }
//                if(prenext > nownext)
//                        temp = to;
//            }




