#include <cstdio>
#include <cstring>
#define MAXN 250

using namespace std;

char a[MAXN], b[MAXN];
int fail[MAXN];
int len;

void getNext(char x[], int m)
{
    int i,j;
    j = fail[0] = -1;
    i = 0;
    while(i<m)
    {
        while(j!=-1 && x[i]!=x[j])
            j=fail[j];
        fail[++i] = ++j;
    }
}

int KMP(char x[], int m, char y[], int n)
{
    int i, j;
    int ans = 0;
    i = j = 0;
    while(i<n)
    {
        while(j!=-1 && x[j]!=y[i])
            j = fail[j];
        i++;
        j++;
        if(j>=m)
        {
            ans++;
            j = fail[j];
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%s%s", a, b);
        len = strlen(a);
        for(int i=0, j=len; i<len; i++, j++)
        {
            a[j] = a[i];
        }
        getNext(b, len);
        puts(KMP(b, len, a, len<<1) ? "Yes" : "No");
    }
    return 0;
}




























