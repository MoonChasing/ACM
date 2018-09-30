#include<cstdio>

using namespace std;

int main()
{
    long long a[51];
    a[1] = a[2] = 1;
    for(int i=3; i<=50; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    printf("%lld\n",a[50]);
    return 0;
}
