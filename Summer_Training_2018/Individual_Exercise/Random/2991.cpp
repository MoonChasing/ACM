#include <cstdio>

typedef long long LL;

using namespace std;

const int MAXN = 1e6+7;
char stock[MAXN];

int main()
{
    scanf("%s", stock);
    FILE * fp = fopen("stock.txt", "w");

    char ch;
    for(int i=0; stock[i]!='\0'; i++)
    {
        ch = stock[i];
        {
            if(ch == '|')
                fputc(10, fp);
            else
                fputc(ch, fp);
        }
    }
    fclose(fp);
    return 0;
}
//2991




