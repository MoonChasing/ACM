#include<cstdio>

using namespace std;

int n;
char mz[7][7];
bool a, b;

void judgeA()
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(j+1 < 5 && j+2<5 && mz[i][j] == mz[i][j+1] && mz[i][j] == mz[i][j+2])
            {
                if(mz[i][j] == 'A')
                    a = true;
                else
                    b = true;
            }
            if(i+1 < 5 && i+2<5 && mz[i][j] == mz[i+1][j] && mz[i][j] == mz[i+2][j])
            {
                if(mz[i][j] == 'A')
                    a = true;
                else
                    b = true;
            }
            if(i+1 < 5 && i+2<5 && j+1<5 && j+2<5 && mz[i][j] == mz[i+1][j+1] && mz[i][j] == mz[i+2][j+2])
            {
                if(mz[i][j] == 'A')
                    a = true;
                else
                    b = true;
            }
            if(i<3 && j>=2 && mz[i][j] == mz[i+1][j-1] && mz[i][j] == mz[i+2][j-2])
            {
                if(mz[i][j] == 'A')
                    a = true;
                else
                    b = true;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        a = b = false;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                mz[i][j] = getchar();
            }
            getchar();
        }
        judgeA();
        if(a && !b)
            puts("A wins");
        else if(!a && b)
            puts("B wins");
        else
            puts("draw");

    }
    return 0;
}
