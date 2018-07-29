#include<stdio.h>

int main()
{
    int h,m;
    scanf("%d:%d", &h, &m);
    if(h>=0 && h<=12)
        printf("Only %02d:%02d. Too early to Dang.\n",h,m);
    else
    {
        if(m == 0)
        {
            for(int i=1; i<=h-12; i++)
                printf("Dang");
            putchar(10);
        }
        else
        {
            for(int i=0; i<=h-12; i++)
                printf("Dang");
            putchar(10);
        }
    }
    return 0;
}
