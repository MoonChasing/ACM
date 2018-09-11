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

struct node
{
    int id, intime, outtime;
    bool operator <(const node & a) const
    {
        return id < a.id;
    }
};
vector<node> ans;

int main()
{
    int T, cmp;
    scanf("%d%d", &T, &cmp);
    node temp;
    int id, in, out;
    while(T--)
    {
        scanf("%d%d%d", &id, &in, &out);
        if(in <= cmp && out >= cmp)
            ans.push_back(node {id, in, out});
    }

    sort(ans.begin(), ans.end());
    for(vector<node>::iterator it = ans.begin(); it!=ans.end(); it++)
        printf("%d\n", it->id);
    return 0;
}











