#include <bits/stdc++.h>

using namespace std;

int T;
int m,R;
int x,y,r;
const double pi = acos(-1);
double d, perimeter;
const double eps = 1e-7;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &m, &R);
        zero = perimeter = 2*pi*R;
        while(m--)
        {
            scanf("%d%d%d", &x, &y, &r);
            d = sqrt(x*x+y*y);
            //相离或包含
            if(R+r<d || R-r>d)
            {
                continue;
            }
            //相切
            else if(fabs(R-r-d)<=eps)
            {
                perimeter += 2*pi*r;
                continue;
            }
            else
            {
                double the1 = 2 * acos( (R*R+d*d-r*r) / (2*R*d) );
                double the2 = 2 * acos( (r*r+d*d-R*R) / (2*r*d) );

                perimeter -= the1*R;
                perimeter += the2*r;
                continue;
            }

        }
        printf("%f\n",perimeter);
    }
    return 0;
}
