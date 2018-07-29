#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 100010;
int tree[25][MAXN]; /*表示每层每个位置的值*/
int sorted[MAXN]; //已经排序好的数
int toleft[25][MAXN]; //toleft[p][i]表示第p层从1到i有多少个数分入左边


void build(int l, int r, int dep)
{
    if(l == r)
        return;
    int mid = (l+r)>>1;
    int same = mid-l+1;
    for(int i=l; i<=r; i++)
        if(tree[dep][i] < sorted[mid])
            same--;     //运行完后有same个sorted[mid]值分入左子树
    int lpos = l;
    int rpos = mid+1;
    for(int i=l; i<=r; i++)
    {
        if(tree[dep][i] < sorted[mid])
            tree[dep+1][lpos++] = tree[dep][i];
        else if(tree[dep][i] == sorted[mid] && same>0)
        {
            tree[dep+1][lpos++] = tree[dep][i];
            same--;
        }
        else
            tree[dep+1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l-1] + lpos - l;    // lpos-l是本区间内分入左子树的个数， toleft[dep][l-1]是之前区间的
    }
            
    build(l,mid,dep+1);
    build(mid+1,r,dep+1);
}

int query(int L, int R, int l, int r, int dep, int k)
{
    if(l==r)
        return tree[dep][l];
    int mid = (L+R)>>1;
    int cnt = toleft[dep][r] - toleft[dep][l-1];    //从 l 到 r有多少个数划分到左子树之中
    if(cnt >= k)                                    //如果 cnt >= k， 则在左区间中查找第k个值
    {
        int newl = L + toleft[dep][l-1] - toleft[dep][L-1];         //新的左边界为原来左边界加上 从L 到 l-1 中划入左子树的数的个数
        int newr = newl+cnt-1;
        return query(L,mid,newl,newr,dep+1,k);
    }
    else                                                            //如果cnt < k， 则在右区间内查找 k-cnt 个数
    {
        int newr = r+toleft[dep][R] - toleft[dep][r];               //新的右边界为 原右边界 加上从r+1到R中划入左子树的个数
        int newl = newr - (r-l-cnt);
        return query(mid+1, R, newl, newr, dep+1, k-cnt);
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        memset(tree, 0, sizeof(tree));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&tree[0][i]);
            sorted[i] = tree[0][i];
        }
        sort(sorted+1, sorted+n+1);
        build(1,n,0);
        int s,t,k;

        while(m--)
        {
            scanf("%d%d%d",&s,&t,&k);
            printf("%d\n",query(1,n,s,t,0,k));
        }
    }
    return 0;

}

/*
    收获：
        1. 划分树用到了 快排的原理、线段树的知识
           在构造树的过程之中，用到了快排的原理，来确定其左子树、右子树，不同的是快排一般以第一个数为关键值， 而划分树以sorted[mid]为键值
           小于sorted[mid]的划入左子树， 大于sorted的划入右子树， 相等的按左右树个数分配

    时间：
        2017年8月22日 16:37:32

    地点：
        学科楼215
*/

/*
    收获：
        2. 范围的缩小：
            以左为例，
             我们是从l开始查找， 所以l之前的我们已经不需要查询了。
            [L, l-1] 有 n 个数划入左子树， 所以新区间的左端点为 L+n。
            这个区间有cnt个数， 所以可以确定右端点为左端点+cnt-1。

    时间：
        2017年8月23日 20:11:44
    
    地点：
        桂苑42-403-3

*/
