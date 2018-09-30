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

int n;
char tmp, nm[MAXN];
LL t, fsz;
string root;
map<string, LL> sz;
map<string, set<string> > dir;

void calsz(string rt)
{
    set<string> s = dir[rt];
    for(set<string>::iterator it = s.begin(); it != s.end(); it++)
    {
        calsz(*it);
        sz[rt] += sz[*it];
    }
}

void solve(string rt)
{
    if(dir[rt].empty())
    {
        printf("  %s %lld\n", rt.c_str(), sz[rt]);
        return;
    }

    bool flag = true;
    set<string> s = dir[rt];
    for(set<string>::iterator it = s.begin(); it != s.end(); it++)
    {
        if(sz[*it] >= t)
            flag = false;
    }



        if(flag)
        {
            printf("+ %s %lld\n",rt.c_str(), sz[rt]);
        }
        else
        {
            printf("- %s %lld\n",rt.c_str(), sz[rt]);

            for(set<string>::iterator it = s.begin(); it != s.end(); it++)
                solve(*it);
        }

}


int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%s%lld", nm, &fsz);
        root = "root";
        for(int i=0; nm[i]; i++)
        {
            if(nm[i] == '/')
            {
                tmp = nm[i+1];
                nm[i+1] = '\0';
                dir[root].insert(nm);
                root = nm;
                nm[i+1] = tmp;
            }
        }
        sz[root] += fsz;
    }
    scanf("%lld", &t);
    calsz("root");
    solve("/");
    return 0;
}













