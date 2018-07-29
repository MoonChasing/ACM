#include<iostream>
#include<cstdio>
#include<cstring>

#define MAXN 50005

//#define DataIn
using namespace std;

int T, num;
int n, BIT[MAXN];
char op[10];                                                                                                                                                                                    
int op1, op2;
int kiss = 1;

int sum(int i)
{
    int s = 0;
    while(i>0)
    {
        s += BIT[i];
        i -= i&-i;
    }
    return s;
}

void add(int i, int x)
{
    while(i<=n)
    {
        BIT[i] += x;
        i += i&-i;
    }
}
int main()
{
    #ifdef DataIn
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif // DataIn
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        memset(BIT, 0, sizeof(BIT));
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &num);
            add(i, num);
        }
        printf("Case %d:\n", kiss++);
        while(scanf("%s", op))
        {
            if(op[0] == 'E')
                break;
            scanf("%d%d", &op1, &op2);
            if(op[0] == 'A')
                add(op1, op2);
            else if(op[0] == 'S')
                add(op1, -op2);
            else
                printf("%d\n", sum(op2)-sum(op1-1));
        }
    }
    return 0;
}
