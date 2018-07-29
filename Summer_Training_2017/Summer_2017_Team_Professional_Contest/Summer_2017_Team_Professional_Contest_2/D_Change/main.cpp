#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

typedef pair<int, int> P;
map<P, int> mp;

void init()
{
    mp[P(2,1)] = 1;
    mp[P(5,1)] = 2;
    mp[P(10,1)] = 2;
    mp[P(20,1)] = 2;
    mp[P(50,1)] = 2;
    mp[P(100,1)] = 2;
    mp[P(200,1)] = 2;
    mp[P(500,1)] = 2;
    mp[P(1000,1)] = 2;
    mp[P(2000,1)] = 2;
    mp[P(5000,1)] = 2;
    mp[P(10000,1)] = 2;

    mp[P(5,2)] = 1;
    mp[P(10,2)] = 1;
    mp[P(20,2)] = 1;
    mp[P(50,2)] = 1;
    mp[P(100,2)] = 1;
    mp[P(200,2)] = 1;
    mp[P(500,2)] = 1;
    mp[P(1000,2)] = 1;
    mp[P(2000,2)] = 1;
    mp[P(5000,2)] = 1;
    mp[P(10000,2)] = 1;

    mp[P(10,5)] = 1;
    mp[P(20,5)] = 1;
    mp[P(50,5)] = 1;
    mp[P(100,5)] = 1;
    mp[P(200,5)] = 1;
    mp[P(500,5)] = 1;
    mp[P(1000,5)] = 1;
    mp[P(2000,5)] = 1;
    mp[P(5000,5)] = 1;
    mp[P(10000,5)] = 1;

    mp[P(20,10)] = 1;
    mp[P(50,10)] = 2;
    mp[P(100,10)] = 2;
    mp[P(200,10)] = 2;
    mp[P(500,10)] = 2;
    mp[P(1000,10)] = 2;
    mp[P(2000,10)] = 2;
    mp[P(5000,10)] = 2;
    mp[P(10000,10)] = 2;

    mp[P(50,20)] = 1;
    mp[P(100,20)] = 1;
    mp[P(200,20)] = 1;
    mp[P(500,20)] = 1;
    mp[P(1000,20)] = 1;
    mp[P(2000,20)] = 1;
    mp[P(5000,20)] = 1;
    mp[P(10000,20)] = 1;

    mp[P(100,50)] = 1;
    mp[P(200,50)] = 1;
    mp[P(500,50)] = 1;
    mp[P(1000,50)] = 1;
    mp[P(2000,50)] = 1;
    mp[P(5000,50)] = 1;
    mp[P(10000,50)] = 1;

    mp[P(200,100)] = 1;
    mp[P(500,100)] = 2;
    mp[P(1000,100)] = 2;
    mp[P(2000,100)] = 2;
    mp[P(5000,100)] = 2;
    mp[P(10000,100)] = 2;

    mp[P(500,200)] = 1;
    mp[P(1000,200)] = 1;
    mp[P(2000,200)] = 1;
    mp[P(5000,200)] = 1;
    mp[P(10000,200)] = 1;

    mp[P(1000,500)] = 1;
    mp[P(2000,500)] = 1;
    mp[P(5000,500)] = 1;
    mp[P(10000,500)] = 1;

    mp[P(2000,1000)] = 1;
    mp[P(5000,1000)] = 2;
    mp[P(10000,1000)] = 2;

    mp[P(5000,2000)] = 1;
    mp[P(10000,2000)] = 1;

    mp[P(10000,5000)] = 1;
}
int main()
{
    #ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif

    int T;
    scanf("%d", &T);
    int kiss = 1;
    init();
    while(T--)
    {
        float a,b;
        scanf("%f%f", &a, &b);
        int A, B;
        A = (int)(100*a+0.1);
        B = (int)(100*b+0.1);
        printf("Case #%d: %.2f\n", kiss++, mp[P(A,B)]==1?0.01:0.02);
    }

    return 0;
}












