#include <bits/stdc++.h>

using namespace std;

int T;
int a,b,x,y;

const double g = 9.8;

int main()
{
    //cout << floor(4.5);
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d%d%d%d", &a, &b, &x, &y);
        x = -x;
        double vx = (b/sqrt(a*a+b*b)) * sqrt(2*g*(y-(double)b*x/a)), ax = b*g/(sqrt(a*a+b*b));
        double vy = (a/sqrt(a*a+b*b)) * sqrt(2*g*(y-(double)b*x/a)), ay = a*g/(sqrt(a*a+b*b));
        double t = 2*vy/ay;
        int ans = 1;
        double deltax;
        double len = x * sqrt(1+b*b/(a*a));
        do
        {
            deltax = vx*t+0.5*ax*t*t;
            vx += ax*t;
            len -= deltax;
            ans++;
        }while(len > 0);
        printf("%d\n", ans);
    }
    return 0;
}
