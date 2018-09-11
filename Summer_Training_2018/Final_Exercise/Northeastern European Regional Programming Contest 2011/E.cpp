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
#define MAXN 300010
#define INF 0x3f3f3f3f
//#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int mo[MAXN];
char gendar[MAXN];

map<int, int> dna;
bool life[MAXN];

int n, m, k;
void init()
{
    for(int i=0; i<MAXN; i++)
    {
        mo[i] = i;
    }
}

int ufind(int x)
{
    if(mo[x] == x)
        return x;
    return mo[x] = ufind(mo[x]);
}

void unite(int x, int y)
{
    x = ufind(x);
    y = ufind(y);

    if(x == y)
        return;
    mo[x] = y;
}

bool same(int x, int y)
{
    return ufind(x) == ufind(y);
}

int main()
{
    freopen("eve.in", "r", stdin);
    freopen("eve.out", "w", stdout);
    init();
    scanf("%d", &n);
    getchar();
    for(int i=1; i<=n; i++)
    {
        gendar[i] = getchar();
        life[i] = true;
        getchar();
    }

    scanf("%d", &m);

    int fa, mot, id, shiji;
    char sex;
    int  tot = n;

    for(int i=1; i<=m; i++)
    {
        scanf("%d", &fa);
        if(fa > 0)  //birth
        {
            tot++;

            scanf("%d %c", &mot, &sex);
            id = tot;

            gendar[id] = sex;
            unite(id, mot);
            life[id] = true;
        }
        else    //die
        {
            life[-fa] = false;
        }
    }


    int cnt = tot;
    scanf("%d", &k);
    int seq;
    set<int> qwer;
    for(int i=1; i<=k; i++)
    {
        scanf("%d%d", &id, &seq);
        //qwer.insert(seq);
        if(dna[seq] != 0)
        {
            // id 和 dna[seq]一个并查集
            unite(id, dna[seq]);
            //mo[id] = dna[seq];
        }
        else
        {
            dna[seq] = ++cnt;
            unite(id, cnt);
        }
    }

    for(int i=1; i<=tot; i++)
        ufind(i);


    set<int> foo;

    for(int i=1; i<=tot; i++)
    {
        if(life[i])
        {
            mot = ufind(i);
            qwer.insert(mot);
            if(mot > tot)
                foo.insert(mot);
        }
    }

#ifdef DEBUG
    puts("-------------------");
    for(int i=1; i<=tot; i++)
        printf("%d%c", mo[i],  " \n"[i==tot]);
    puts("-------------------");
#endif // DEBUG

    if(qwer.size() <= 1)
        puts("YES");
    else if(foo.size() >= 2)
        puts("NO");
    else
        puts("POSSIBLY");


    return 0;
}
