#include <bits/stdc++.h>

using namespace std;

int T;
int m,R;
int x,y,r;
const double pi = acos(-1);
double d, perimeter;
const double eps = 1e-7;
double zero;

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
                continue;
            //相切
            else if(fabs(R-r-d)<=eps)
            {
                perimeter += 2*pi*r;
                continue;
            }
            //相交且另一圆圆心在圆外
            //if(d>R)
            else
            {
                double the1 = 2 * acos( (R*R+d*d-r*r) / (2*R*d) );
                double the2 = 2 * acos( (r*r+d*d-R*R) / (2*r*d) );
                if(the2>180)
                    the2 = 360-the2;
                perimeter -= (the1/360)*zero;
                perimeter += (the2/360)*(2*pi*r);
                continue;
            }
//            if(fabs(d-R)<=eps)
//            {
//
//            }

        }
        printf("%f\n",perimeter);
    }
    return 0;
}
