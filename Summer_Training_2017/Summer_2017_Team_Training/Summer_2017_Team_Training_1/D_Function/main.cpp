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
#define MAXN 100005
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

int N, M;
int a[MAXN], f[MAXN * 4];

void build(int x, int l, int r) //xΪ����ţ�l��rΪ����������Χ
{
    if (l == r)
    {
        scanf("%d", &f[x]);
        a[l] = f[x];
    }
    else 
    {
        int mid = (l + r) >> 1;
        build(x * 2, l, mid);
        build(x * 2 + 1, mid + 1, r);
        f[x] = min(f[x * 2], f[x * 2 + 1]);
    }
}

int findn(int x, int l, int r, int ll, int rr, int u) //xΪ����ţ� l��rΪ��㷶Χ�� ll��rrΪҪ��ѯ�ķ�Χ�� uΪҪ�Ƚϵ�ֵ
{
    if (f[x] > u)
        return rr + 1;
    if (ll <= l && r <= rr)
    {
        if (l == r)
            return l;
        int mid = l + r >> 1;
        if (f[x * 2] <= u)
            return findn(2 * x, l, mid, ll, rr, u);
        else
            return findn(2 * x + 1, mid + 1, r, ll, rr, u);
    }
    else
    {
        int mid = l + r >> 1, res;
        if (ll <= mid)
        {
            res = findn(2 * x, l, mid, ll, rr, u);
            if (res <= rr)
                return res;
        }
        if (rr > mid)
        {
            res = findn(2 * x + 1, mid + 1, r, ll, rr, u);
            if (res <= rr)
                return res;
        }
        return rr + 1;
    }
}

int main()
{
    int T, ans;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        build(1, 1, N);
        scanf("%d", &M);
        while (M--)
        {
            int L, R;
            scanf("%d%d", &L, &R);
            int ans = a[L];
            while (L < R)
            {
                int q = findn(1, 1, N, L + 1, R, ans);
                if (q < R)
                    ans %= a[q];
                L = q;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
