#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
struct Date
{
    int y;//year
    int m;//month
    int d;//day in month
};
bool isLeap(int y)//判断是否是闰年
{
    return y%4==0&&y%100!=0||y%400==0;//真返回为1，假为0
}
int daysOfMonth(int y,int m)
{
    int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(m!=2)
        return day[m-1];
    else
        return 28+isLeap(y);
}
int daysOfDate(Date d)//计算一共的天数
{
    int days=d.d;
    for(int y=1;y<d.y;y++)//计算年
        days+=365+isLeap(y);
    for(int m=1;m<d.m;m++)//计算月
        days+=daysOfMonth(d.y,m);
    //days+=d.d;
    return days;
}

int difference(Date d1, Date d2)
{
    return abs(daysOfDate(d1) - daysOfDate(d2));
}

int  T;

int main()
{
    Date d1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d-%d-%d", &d1.y, &d1.m, &d1.d);

        for(int i=d1.y+1; ;i+=1)
        {
            Date d2 = {i, d1.m, d1.d};
            if(difference(d1,d2) % 7 == 0)
            {printf("%d\n", i);
            break;}

        }
    }

    return 0;
}
