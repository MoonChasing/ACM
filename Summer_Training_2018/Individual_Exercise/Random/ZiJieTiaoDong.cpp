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
    int l, r;
    bool operator < (const node & a)
    {
        return l!=a.l ? l<a.l : r<a.r;
    }
};

vector<node> data;
vector<node> ans;
int n, m;
int l, r;
int a, b;
int j;
char ch;
int main()
{
    scanf("%d", &m);
    while(m--)
    {
        do{
            scanf("%d,%d", &l, &r);
            data.push_back(node {l, r});
            ch = getchar();
        }while(ch != '\n');
    }
    sort(data.begin(), data.end());
    n = data.size();
    for(int i=0; i<n; i=j)
    {
        a = data[i].l;
        b = data[i].r;
        j = i+1;
        while(j < n && data[j].l <= b)
        {
            b = max(b, data[j].r);
            j++;
        }
        ans.push_back(node {a, b});
    }
    int len = ans.size();
    for(int i=0; i<len; i++)
        printf("%d,%d%c", ans[i].l, ans[i].r, ";\n"[i==len-1]);
    return 0;
}












