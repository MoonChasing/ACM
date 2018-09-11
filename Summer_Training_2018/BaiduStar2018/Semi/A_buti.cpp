#include <functional>
#include  <algorithm>
#include   <iostream>
#include    <cstring>
#include    <cstdlib>
#include     <vector>
#include     <cstdio>
#include     <cctype>
#include     <bitset>
#include      <stack>
#include      <queue>
#include      <cmath>
#include      <ctime>
#include       <list>
#include        <map>
#include        <set>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
const LL mod = 1e9+7;
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;

const int MAXN = 1e5 + 100;
int fa[MAXN];
vector<int> ve[MAXN];
struct node{
    int fa,num;
}e[MAXN];
bool cmp(node a,node b){
    return a.num>b.num;
}
bool cmp1(node a,node b){
    return a.num<b.num;
}
int mark[MAXN];
signed  main()
{
    int i,j,k,n,m;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        fa[1] = 0;
        for(i = 2;i <= n;i ++)
        {
            scanf("%d",&fa[i]);
        }
        LL MAX = 0;
        LL MIN = 0;
        for(i = 1;i <= n;i++)
        {
            scanf("%d",&k);
            e[i].num = k;
            e[i].fa = fa[i];
        }
        sort(e+1,e+1+n,cmp);
        memset(mark,0,sizeof(mark));
        MAX = max(e[1].num,0);
        mark[e[1].fa] = 1;
        bool flag = 0;
        for(i = 2;i <= n;i++){
            if(e[i].num>0){
                if(mark[e[i].fa] < 2){
                    if(mark[e[i].fa] == 0){
                        MAX += e[i].num;
                        mark[e[i].fa]++;
                    }
                    else{
                        if(!flag){
                            MAX += e[i].num;
                            mark[e[i].fa]++;
                            if(mark[e[i].fa] == 2)
                            flag = 1;
                        }
                    }
                }
            }
        }
        flag = 0;
        memset(mark,0,sizeof(mark));
        sort(e+1,e+1+n,cmp1);
        MIN = min(0,e[1].num);
        mark[e[1].fa] = 1;
        for(i = 2;i <= n;i++){
            if(e[i].num<0){
                if(mark[e[i].fa] < 2){
                    if(mark[e[i].fa] == 0){
                        MIN += e[i].num;
                        mark[e[i].fa]++;
                    }
                    else{
                        if(!flag){
                            MIN += e[i].num;
                            mark[e[i].fa]++;
                            if(mark[e[i].fa] == 2)
                            flag = 1;
                        }
                    }
                }
            }
        }
        printf("%lld %lld\n",MAX,MIN);
    }
    return 0;
}