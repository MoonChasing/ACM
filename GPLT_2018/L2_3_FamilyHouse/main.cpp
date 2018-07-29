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

struct person
{
    int id;
    int hnum;
    int harea;
};

struct family
{
    int id;
    int pernum;
    double hnum;
    double harea;
};

person pe[MAXN];
family fam[MAXN];
bool vis[MAXN];
bool exist[MAXN];
vector<int> E[MAXN];

bool cmp(family a, family b)
{
    if(a.harea > b.harea)
        return true;
    else if(a.harea < b.harea)
        return false;
    else
    {
        if(a.id < b.id)
            return true;
        else
            return false;
    }
}

int n;

void dfs(int u, int &personnum, int &familid, int &familyhouse, int &familyarea)
{
    vis[u] = true;
    familid = min(familid, u);
    personnum++;
    familyarea +=pe[u].harea;
    familyhouse += pe[u].hnum;

    for(int i=0; i<E[u].size(); i++)
    {
        int v = E[u][i];
        if(!vis[v])
            dfs(v, personnum, familid, familyhouse, familyarea);
    }
}

int main()
{
    memset(vis, false, sizeof(vis));
    memset(exist, false, sizeof(exist));
    scanf("%d", &n);
    int id, dedid, momid, childnun, childid, housenum, area;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &id);
        exist[id] = true;
        pe[id].id = id;
        scanf("%d%d", &dedid, &momid);
        if(~dedid)
        {
        E[id].push_back(dedid);
        E[dedid].push_back(id);
        }
        if(~momid)
        {
        E[id].push_back(momid);
        E[momid].push_back(id);
        }
        scanf("%d", &childnun);
        for(int i=1; i<=childnun; i++)
        {
            scanf("%d", &childid);
            E[id].push_back(childid);
            E[childid].push_back(id);
        }
        scanf("%d%d", &housenum, &area);
        pe[id].hnum = housenum;
        pe[id].harea = area;
    }

    int cnt = 0;
    int personnum, familyid, familyhouse, familyarea;
    for(int i=0; i<MAXN; i++)
    {
        if(!vis[i] && exist[i])
        {
            personnum = 0;
            familyid =INF;
            familyhouse = 0;
            familyarea = 0;
            dfs(i, personnum, familyid, familyhouse, familyarea);
            fam[cnt].id = familyid;
            fam[cnt].pernum = personnum;
            fam[cnt].hnum = familyhouse / (double)personnum;
            fam[cnt].harea = familyarea / (double)personnum;
            cnt++;
        }
    }
    sort(fam, fam+cnt, cmp);
    printf("%d\n",cnt);
    for(int i=0; i<cnt; i++)
    {
        printf("%04d %d %.3f %.3f\n", fam[i].id, fam[i].pernum, fam[i].hnum, fam[i].harea);
    }
    return 0;
}









