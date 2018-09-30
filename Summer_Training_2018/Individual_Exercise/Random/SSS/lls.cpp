#include <cstdio>
#define MAXN 9000010
typedef long long LL;

using namespace std;

int arr[MAXN];
int main()
{
    int len;
    scanf("%d", &len);
    for(int i=0; i<len; i++)
        scanf("%d", arr+i);

    int i;
	LL MaxSum = 0;
	LL CurSum = 0;
	for(i=0;i<len;i++)
	{
		CurSum += arr[i];
		if(CurSum > MaxSum)
			MaxSum = CurSum;
		if(CurSum < 0)
			CurSum = 0;
	}
	printf("%lld\n", MaxSum);
    return 0;
}












