#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

bool isLeap(int y)//判断是否是闰年
{
    return y%4==0&&y%100!=0||y%400==0;//真返回为1，假为0
}

bool nextfourisleap(int y)
{
    y+=4;
    return y%4==0&&y%100!=0||y%400==0;
}

int f(int y, int m, int d)
{
    if(isLeap(y))
    {
        if( m==1 || (m==2 && d<=28))
            return 366;
        else
            return 365;
    }
    else
    {
        if(m==1 || (m==2 && d<=28))
            return 365;
        else if(isLeap(y+1))
            return 366;
        else
            return 365;
    }
}
int  T;

int main()
{
    scanf("%d", &T);
    int y,m,d;
    while(T--)
    {
        scanf("%d-%d-%d", &y, &m, &d);
        int sum = 0;
        if( m==2 && d==29)
        {
            int cnt = 0;
            int temp = y;
            while(1)
            {
                if(nextfourisleap(temp))
                {
                    sum += 365+365+365+366;
                    temp += 4;
                }
                else
                {
                    sum += 365*4;
                    temp+=4;
                }
                if(sum %7 == 0)
                {
                    printf("%d\n",temp);
                    break;
                }
            }
        }
        else
        {
            for(int i=y; ; i++)
            {

                    sum += f(i, m, d);
                    if(sum % 7 == 0)
                    {
                        printf("%d\n", i+1);
                        break;
                    }
                }
            }
        }



    return 0;
}
