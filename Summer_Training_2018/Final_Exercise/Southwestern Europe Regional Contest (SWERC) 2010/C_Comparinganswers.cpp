#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 1005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn

using namespace std;

typedef long long LL;
typedef vector<int> vec;
typedef vector<vec> mat;
int n;

vec mul(mat &A, vec &B)
{
    vec C(A.size());
    for(int i=0; i<A.size(); i++)
        for(int j=0; j<B.size(); j++)
            C[i] += A[i][j] * B[j];
    return C;
}

int main()
{
    while(scanf("%d", &n) && n)
    {
        mat A(n, vec(n)), B(n, vec(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &A[i][j]);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &B[i][j]);

        vec C(n), D(n), E(n);
        srand((unsigned)time(0));
        for(int i=0; i<n; i++)
            D[i] = rand()%100+3;
        C = mul(A, D);
        C = mul(A, C);
        E = mul(B, D);
        bool flag = true;
        for(int i=0; i<n; i++)
            if(C[i] != E[i])
            {
                flag = false;
                break;
            }
        if(flag)
            puts("YES");
        else
            puts("NO");

    }
    return 0;
}












