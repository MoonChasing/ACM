#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=10000+5;
ll pr[N];
int main()
{
    ll h=1;
    cin.tie(0);
    ios::sync_with_stdio(0);
    for(ll i=19;;i+=9)
    {
        ll c=i,ans=0;
        while(c)
        {
            ans+=c%10;
            c/=10;
        }
        if(ans==10)
        pr[h++]=i;
        if(h==10003) break;
    }
    int n;
    cin>>n;
    cout<<pr[n]<<endl;
}
