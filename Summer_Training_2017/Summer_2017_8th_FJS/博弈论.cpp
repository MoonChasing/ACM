#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

#define MAXN 10000000
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

char Alice[MAXN];
char Bob[MAXN];
int next[MAXN];

void kmp_pre(char x[], int m, int next[])
{
    int i,j;
    j = next[0] = -1;
    i = 0;

    while(i<m)
    {
        while(-1 != j && x[i] != x[j])
            j = next[j];
        next[++i] = ++j;
    }
}

int KMP_Count(char x[],int m,char y[],int n)
{
    //x是模式串， y是主串
    int i,j;
    int ans=0;
    //preKMP(x,m,next);
    kmp_pre(x,m,next);
    i=j=0;
    while(i<n)
    {
        while(-1!=j && y[i]!=x[j])j=next[j];
        i++;
        j++;
        if(j>=m)
        {
            ans++;
            return ans;
        }
    }
    return ans;
}

bool isSame(char A[],int lenA, char B[], int lenB)
{
    char *pA = A;
    char *pB = B;
    for(int i=0; i<lenB; i++)
        if(pA[i] != pB[i])
            return false;
    return true;
}

int main()
{
    int rnd = 1;
    scanf("%s%s",Alice,Bob);
    int lenA = strlen(Alice);
    int lenB = strlen(Bob);

    while(1)
    {

        if(lenA == lenB)
        {
            if(strcmp(Alice,Bob) == 0)
            {
                puts("Alice");
                break;
            }
            if( strcmp(Alice,strrev(Bob)) == 0)
            {
                puts("Alice");
                break;
            }
            else
            {
                puts("Bob");
                break;
            }
        }

        else if(lenA < lenB)
        {
            puts("Bob");
            break;
        }
        else
        {
            //Round Alice
            if(rnd == 1)
            {
                if( isSame(Alice, lenA, Bob, lenB) )
                {
                    puts("Alice");
                    break;
                }
                else if( isSame(strrev(Alice), lenA, Bob, lenB) )
                {
                    puts("Alice");
                    break;
                }
                else
                {
                    Alice[--lenA] = '\0';
                    rnd = 0;
                }
            }
            //Round: Bob
            else
            {

            }
        }
    }
    return 0;
}
