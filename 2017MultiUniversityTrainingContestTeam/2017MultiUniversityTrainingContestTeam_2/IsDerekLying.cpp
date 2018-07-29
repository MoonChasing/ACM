//team595
//B16041432
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXN 80010

using namespace std;

char de[MAXN];
char al[MAXN];

int sameNum(int n)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
        if( de[i] == al[i])
            cnt++;
    return cnt;
}
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int N, scDe, scAl;
        scanf("%d%d%d%s%s",&N, &scDe, &scAl, de, al);
        int same = sameNum(N);
        int diff = N-same ;
        int fencha = abs(scDe-scAl);

        if( fencha > diff )
            printf("Lying\n");
        else if(diff > 2*N-scAl-scDe )
            printf("Lying\n");
        else if(scDe>N || scAl>N)
            printf("Lying\n");
        else
            printf("Not lying\n");

    }
    return 0;
}
