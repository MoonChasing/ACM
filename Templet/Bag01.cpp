#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXN 100005
int c[MAXN], p[MAXN];

int main()
{
    int N,K;
    while(~scanf("%d%d",&N, &K) )
    {
        for(int i=0; i<N; i++)
        {
            scanf("%d%d",c+i, p+i);
        }
        int maxValue=0;
        int remMoney=K;
        int val=0;
        int num = 0;
        bool ok = false;

        for(int i=0; i<N; i++)
        {
            if(K >= c[i] )
            {
                val = p[i];
            }

            for(int j=i+1; j<N; j++)
            {
                remMoney =  K - c[i];
                if( remMoney >= c[j])
                {
                    val += p[j];
                    maxValue = max(val, maxValue);
                    ok = true;
                }
            }
        }
        if(!ok)
            printf("0\n");
        else
            printf("%d\n",maxValue);
    }

    return 0;
}
