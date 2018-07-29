#include <cstdio>
#include <cstring>

int main()
{
    int n, i, sum, cnt, flag, a[27];
    char c;
    while(~scanf("%d",&n))
    {
        getchar();
        sum = cnt = 0;
        memset(a, 0, sizeof(a));
        for(i=0; i<n; i++)
        {
            c = getchar();
            a[c-'a']++;
        }
        do
        {
            flag = 0;
            for(i=0; i<27; i++)
            {
                if(a[i])
                {
                    if(flag)
                    {
                        a[i]--;
                        cnt++;
                    }
                    else
                    {
                        flag = 1;
                        a[i]--;
                        cnt++;
                        sum++;
                    }
                }
                else
                    flag = 0;

            }
        }while(cnt != n);
        printf("%d\n",sum);
    }
    return 0;
}
