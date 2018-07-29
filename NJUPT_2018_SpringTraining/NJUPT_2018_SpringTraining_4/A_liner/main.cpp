#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define mem(x,y) memset(x,y,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define eps 1e-8;
#define INF 100000000
#define MAXN 500
using namespace std;
typedef long long ll;

char b[11]="pqruvwxyz";
int a[11];
bool judge()
{
    for(int i=0; i<10; i++)
        if(a[i]!=0)
            return 0;


    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<10; i++)
            cin>>a[i];

        bool first=1;
        for(int i=0; i<9; i++)
        {
            if(a[i]!=0)
            {
                if(a[i]>0&&!first)
                    cout<<'+';

                cout<<a[i]<<b[i];

                if(first)
                    first=0;
            }
        }
        if(a[9]>0)
            cout<<'+';
        if(a[9]!=0)
            cout<<a[9];

        if(judge())
            cout<<0;
        cout<<endl;
    }

    return 0;
}
