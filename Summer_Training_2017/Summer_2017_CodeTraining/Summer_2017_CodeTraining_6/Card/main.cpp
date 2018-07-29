#include <iostream>
#include <cstdio>

using namespace std;

int card[120];


int main()
{
    int T;
    scanf("%d",&T);
    for(int kase=1; kase<=T; kase++)
    {
        for(int i=1; i<=52; i++)
            scanf("%d",card+i);
        int n, l ,r;
        scanf("%d%d%d", &n, &l, &r);
        n %= r;

        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=r-l+1; k++)
                card[60+k] = card[l+k-1];

            for(int k=l-1, t=0; k>=1; k--, t++)
                card[r-t] = card[k];

            for(int k=1; k<=r-l+1; k++)
                card[k] = card[60+k];

        }
        printf("Case #%d:",kase);
        for(int i=1; i<=52; i++)
            printf(" %d", card[i]);
        putchar(10);
    }
    return 0;
}
