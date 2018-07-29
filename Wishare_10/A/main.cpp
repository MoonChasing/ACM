#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    int a,b,c;

    while(T--)
    {
        cin>>a>>b>>c;
        int maxx, minn, mid;
        maxx = max(a, max(b,c));
        minn = min(a, min(b,c));
        mid = a+b+c-maxx-minn;
        int diff = maxx - minn + maxx - mid;

        int ans;
        if(diff & 1)
        {
            ans = diff / 2 + 2;
        }
        else
            ans = diff / 2;
        cout << ans << endl;
    }
    return 0;
}
