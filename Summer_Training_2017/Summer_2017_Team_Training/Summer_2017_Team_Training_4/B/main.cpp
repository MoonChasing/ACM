#include<cstdio>
#include<algorithm>

using namespace std;

const int N=10005;
int pos[N];
int main()
{
    int n,flag;
    while(scanf("%d",&n) && n)
    {
        getchar();
        for(int i=0,num ; i<n; i++)
        {
            scanf("%d",&num);
            pos[num]=i;
        }
        flag=0;
        for(int i=1; !flag&&i<n-1; i++)
            for(int j=1,lim = min(n-1-i,i); !flag && j<=lim; j++)
                if((pos[i+j]-pos[i])*(pos[i-j]-pos[i])<0)
                    flag = 1;
        printf("%s\n",flag ? "no" : "yes");
    }
    return 0;
}
