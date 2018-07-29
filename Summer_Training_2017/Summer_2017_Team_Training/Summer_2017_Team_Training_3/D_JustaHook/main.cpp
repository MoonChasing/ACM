#include<cstdio>
#include<iostream>
#include<cstring>

#define LOCAL
//#define DEBUG
#define MAXN 100010
using namespace std;

int T, n, Q;
int kiss = 1;
int X,Y, kind;
c
int main()
{
    #ifdef LOCAL
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n,&Q);
        build(1, 1, n);

        while(Q--)
        {
            scanf("%d%d%d",&X,&Y,&kind);
            update(1, 1, n, X, Y, kind);
        }
         printf("Case %d: The total value of the hook is %d.\n", kiss++, SegTree[1].val);
        #ifdef DEBUG
        for(int i=1; i<=40; i++)
            printf("%2d:%5d\n", i, SegTree[i].val);
        #endif

    }

    return 0;
}
