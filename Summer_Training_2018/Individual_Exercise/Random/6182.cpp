#include <cstdio>
#include <iostream>
#include<cmath>

typedef long long ll;

using namespace std;

bool isfourthpower(ll x)
{
    int l = 0, r = 10000;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if((ll)pow(mid,4)<=x)
            l=mid+1;
        else
            r=mid-1;
    }
    if((ll)pow(r,4)==x)
        return true;
    else
        return false;
}
int main()
{
    ll n;
    scanf("%lld", &n);
    cout << isfourthpower(n);
    return 0;
}









