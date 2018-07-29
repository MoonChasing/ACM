#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand((unsigned)time(NULL));
    int T;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        int a = rand()%2;
        if(a==1)
            printf("Yes\n");
        else
            printf("NO\n");
    }

    return 0;
}



