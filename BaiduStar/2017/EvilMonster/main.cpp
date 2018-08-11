//#include<bits/stdc++.h>
//#define MAXN 1050
//
//#define LL long long
//using namespace std;
//int n,m;
//LL  dp[MAXN][11]={0};
//LL  num[MAXN][11]={0};
//int spend[MAXN],power[MAXN];
//LL  ans=0;
//int cika[MAXN];
//struct skill
//{
//    int power;
//    int spend;
//}a[MAXN];
//
//int main()
//{
//        while(~scanf("%d%d",&n,&m))
//        {
//            ans=0;
//            memset(num,0,sizeof(num));
//            memset(dp,0,sizeof(dp));
//            memset(cika,0,sizeof(cika));
//
//            int powerMax=0,defMax=0,HPMax=0;
//            int lx,ly;
//            for(int i=0;i<n;i++)
//            {
//                scanf("%d%d",&lx,&ly);
//                num[lx][ly]++;
//                if(defMax<ly)defMax=ly;
//                if(HPMax<lx)HPMax=lx;
//            }
//            int moon=0;
//            for(int i=0;i<m;i++)
//            {
//                scanf("%d%d",&lx,&ly);
//                if(cika[ly]!=0&&cika[ly]<=lx)
//                    continue;
//                cika[ly]=lx;
//                a[moon].spend=lx;a[moon].power=ly;
//                if(a[moon].power>powerMax)
//                {
//                    powerMax=a[moon].power;
//                }
//                moon++;
//            }
//            m=moon;
//            if(powerMax<=defMax)
//            {
//                printf("-1\n");
//                continue;
//            }
//            for(int defence=0;defence<=10;defence++)
//            {
//                if(defence!=0)
//                    for(int i=0;i<m;i++)
//                    {
//                        a[i].power--;
//                    }
//
//                for(int i=1;i<=HPMax;i++)
//                {
//                    LL t=-1;
//                    for(int j=0;j<m;j++)
//                    {
//                        if(a[j].power<=0)
//                            continue;
//                        if(i-a[j].power<=0)
//                        {
//                            if(t==-1||t>a[j].spend)
//                            {
//                                t=a[j].spend;
//                            }
//                            continue;
//                        }
//                        if(t==-1||t>dp[i-a[j].power][defence]+a[j].spend)
//                        {
//                            t=dp[i-a[j].power][defence]+a[j].spend;
//                        }
//                    }
//                    dp[i][defence]=t;
//                }
//            }
//            for(int i=0;i<=HPMax;i++)
//            {
//                for(int j=0;j<=10;j++)
//                {
//                    ans+=(dp[i][j]*num[i][j]);
//                }
//            }
//            printf("%I64d\n",ans);
//        }
//
//}

#include<cstdio>

using namespace std;

int main()

{
    a++;
    return 0;
}
