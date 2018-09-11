#include <iostream>
#include <cstring>

#define MAXN 100001
#define Low_bit(x) (x&(-x))

using namespace std;

int d[MAXN],n;

void update(int a)
{
    while(a<=MAXN)   //֮���Բ���a<=n,��Ϊ�˳�����������з�������������Ȼ���ã���:18 14 16 5 1��
    {
        d[a]++;
        a+=Low_bit(a);
    }
}

int get_sum(int a)
{
    int sum=0;
    while(a)
    {
        sum+=d[a];
        a-=Low_bit(a);
    }
    return sum;
}

int main()
{
    int a,ans;
    cin>>n;
    memset(d,0,sizeof(d));
    ans=0;
    for(int i=1;i<=n;i++)
    {
       cin>>a;
       update(a);
       ans+=i-get_sum(a);
    }
    cout<<ans<<endl;
    return 0;
}
