#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char board[4][4];

void init()
{
    memset(board, '.', sizeof(board));
}

bool ifWin(char c)
{
    for(int i=1; i<=3; i++)
        if(board[i][1] == board[i][2] && board[i][1] == board[i][3] && board[i][1] == c)
            return true;
    for(int j=1; j<=3; j++)
        if(board[1][j] == board[2][j] && board[1][j] == board[3][j] && board[1][j] == c)
            return true;
    if(board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == c)
        return true;
    if(board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == c)
        return true;
    return false;
}
bool canWin(char c)
{
    int ans=0;
    for(int i=1; i<=3; i++)
    {
        int cntc = 0, cntb = 0;
        for(int j=1; j<=3; j++)
        {
            if(board[i][j] == c)
                cntc++;
            else if(board[i][j] == '.')
                cntb++;
        }
        if(cntc == 2 && cntb == 1)
            ans++;
    }

    for(int j=1; j<=3; j++)
    {
        int cntc = 0, cntb = 0;
        for(int i=1; i<=3; i++)
        {
            if(board[i][j] == c)
                cntc++;
            else if(board[i][j] == '.')
                cntb++;
        }
        if(cntc == 2 && cntb == 1)
            ans++;
    }

    int cntc = 0, cntb = 0;
    for(int i=1; i<=3; i++)
    {
        if(board[i][i] == c)
            cntc++;
        else if(board[i][i] == '.')
            cntb++;
    }
    if(cntc == 2 && cntb == 1)
        ans++;

    cntb = cntc = 0;
    for(int i=1; i<=3; i++)
    {
        if(board[i][4-i] == c)
            cntc++;
        else if(board[i][4-i] == '.')
            cntb++;
    }
    if(cntc == 2 && cntb == 1)
        ans++;

    if(ans >= 2)
        return true;
    else
        return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        init();
        int flag = 0;
        char c;
        for(int i=1; i<=3; i++)
        {
            for(int j=1; j<=3; j++)
                scanf("%c%c",&board[i][j],&board[0][0]);
        }
//        for(int i=1; i<=3; i++)
//        {
//            for(int j=1; j<=3; j++)
//                printf("%c",board[i][j]);
//            putchar(10);
//        }
        scanf("%c",&c);
        getchar();
        for(int i=1; i<=3; i++)
        {
            for(int j=1; j<=3; j++)
            {
                if(board[i][j] == '.')
                {
                    board[i][j] = c;
                    if(flag == 0 && (ifWin(c) || canWin(c)))
                    {
                        puts("Kim win!");
                        flag = 1;
                    }
                    board[i][j] = '.';
                }
            }
        }

        if(flag == 0)
        {
            puts("Cannot win!");
        }


    }
    return 0;
}
