#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;

char pai[1005][1005];

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    char ch;
    int hang=1 , lie=1;

    int cnt = 0;
    memset(pai, ' ', sizeof(pai));


    while((ch= getchar()) != 10)
    {
        if(hang == n+1)
        {
            hang = 1;
            lie++;
            cnt = 0;
        }

        pai[hang][lie] = ch;
        cnt++;
        hang++;
    }


    for(int i = 1; i<=n; i++)
    {
        for(int j=lie; j>=1; j--)
            printf("%c", pai[i][j]);
        putchar(10);
    }
    return 0;
}
