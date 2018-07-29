#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define maxn 300000


struct Query
{
    int x, y; // qt==3 [x,y]  qt==1||2 a[x]=y
    int qt; // query type 1 for increase 2 for decrease 3 for query
    int cur; // the current contribution
    int k; // the query is the k-th smalleset
    int index;
}q[maxn];
int qtop;

int a[maxn];
int b[maxn];
int bsize;
int n, m;
int tot;
int ans[maxn];
int ansid;

int tmp[maxn];
Query q1[maxn], q2[maxn];
int bit[maxn];
void add(int x, int v)
{
    while (x <= n){
        bit[x] += v;
        x += x&(-x);
    }
}

int query(int x)
{
    int ret = 0;
    while (x > 0){
        ret += bit[x];
        x -= x&(-x);
    }
    return ret;
}


void solve(int head, int tail, int l, int r)
{
    if (head > tail) return;
    if (l == r){
        for (int i = head; i <= tail; ++i){
            if (q[i].qt == 3) ans[q[i].index] = l;
        }
        return;
    }
    int mid = (l + r) >> 1;
    // 将所有<=mid的操作作一遍，tmp[i]存的是[head,tail]里<=mid的操作对询问的贡献
    for (int i = head; i <= tail; ++i){
        if (q[i].qt == 1 && q[i].y <= mid){
            add(q[i].x, 1);
        }
        else if (q[i].qt == 2 && q[i].y <= mid){
            add(q[i].x, -1);
        }
        else{
            tmp[i] = query(q[i].y) - query(q[i].x - 1);
        }
    }
    // 将操作撤销一下
    for (int i = head; i <= tail; ++i){
        if (q[i].qt == 1 && q[i].y <= mid){
            add(q[i].x, -1);
        }
        else if (q[i].qt == 2 && q[i].y <= mid){
            add(q[i].x, 1);
        }
    }
    // 将操作划分成两部分
    int l1=0, l2 = 0;
    for (int i = head; i <= tail; ++i){
        if (q[i].qt == 3){
            // 如果前面的数加上当前的数>=q[i].k，说明该询问的可行区间在[l,mid]，往左划分
            if (q[i].cur + tmp[i] >= q[i].k){
                q1[++l1] = q[i];
            }
            else{
                // 否则往右划分，并记下贡献
                q[i].cur += tmp[i];
                q2[++l2] = q[i];
            }
        }
        else{
            if (q[i].y <= mid) q1[++l1] = q[i];
            else q2[++l2] = q[i];
        }
    }

    for (int i = 1; i <= l1; ++i) {
        q[head + i - 1] = q1[i];
    }
    for (int i = 1; i <= l2; ++i){
        q[head + l1 + i - 1] = q2[i];
    }
    solve(head, head + l1 - 1, l, mid);
    solve(head + l1, tail, mid + 1, r);
}


int main()
{
    int T; cin >> T;
    while (T--)
    {
        scanf("%d%d", &n, &m);
        qtop = 0;tot = 0;
        for (int i = 1; i <= n; ++i){
            scanf("%d", a + i);
            b[tot++] = a[i];
            q[++qtop].qt = 1;
            q[qtop].x = i;
            q[qtop].y = a[i];
        }
        char cmd[4];
        int xi, yi,ki;
        ansid = 0;
        for (int i = 0; i < m; ++i){
            scanf("%s", cmd);
            if (cmd[0] == 'Q'){
                scanf("%d%d%d", &xi, &yi, &ki);
                q[++qtop].x = xi; q[qtop].y = yi; q[qtop].k = ki;
                q[qtop].qt = 3; q[qtop].cur = 0; q[qtop].index = ++ansid;
            }
            else{
                scanf("%d%d", &xi, &yi);
                q[++qtop].x = xi; q[qtop].y = a[xi]; q[qtop].qt = 2;
                q[++qtop].x = xi; q[qtop].y = yi; q[qtop].qt = 1;
                a[xi] = yi;
                b[tot++] = yi;
            }
        }
        sort(b, b + tot);
        bsize = unique(b, b + tot) - b;

        for (int i = 1; i <= qtop; ++i){
            if (q[i].qt == 1 || q[i].qt == 2){
                q[i].y = lower_bound(b, b + bsize, q[i].y) - b + 1;
            }
        }
        solve(1, qtop, 1, bsize);
        for (int i = 1; i <= ansid; ++i){
            printf("%d\n", b[ans[i]-1]);
        }
    }
    //system("pause");
    return 0;
