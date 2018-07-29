#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

const int MAXN=200010;

struct num
{
    int val;
    int w;

    bool operator < (num & a)
    {
        if( val> a.val)
            return false;
        else if( val < a.val)
            return true;
        else
        {
            return w < a.w;
        }
    }

    bool operator == (num & a)
    {
        return val == a.val && w == a.w;
    }

    bool operator > (num & a)
    {
        if( val > a.val)
            return true;
        else if(val < a.val)
            return false;
        else
        {
            return w > a.w;
        }
    }

    bool operator <= (num & a)
    {
        return *this<a || *this == a;
    }

    bool operator >= (num & a)
    {
        return *this>a || *this ==a;
    }
};

num a[MAXN], b[MAXN];

//�ö��ֲ��ҵķ����ҵ�һ��λ�ã�ʹ��temp>b[i-1] ����temp<b[i],����temp����b[i]
int Search(num temp,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=low+high>>1;
        if(temp >= b[mid])
            low=mid+1;
        else high=mid-1;
    }
    return low;
}

int DP(int n)
{
    int i,len,pos,w;
    b[1]=a[1];
    len=1;
    w = 0;
    for(i=2; i<=n; i++)
    {
        if(a[i]>=b[len])//���a[i]��b[]��������󻹴�ֱ�Ӳ��뵽���漴��
        {
            len=len+1;
            w += a[i].w;
            b[len]=a[i];
        }
        else//�ö��ֵķ�����b[]�������ҳ���һ����a[i]���λ�ò�����a[i]������λ��
        {
            pos=Search(a[i],1,len);
            if(b[pos].w > a[i].w)
            {}
            else
                b[pos]=a[i];
        }

    }
    return w;
}



int main()
{

    #ifdef DataIn
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    int shu;
    int cnt = 0;
    int w;
    while(~scanf("%d", &shu))
    {
        if(shu < 0)
            w = 0;
        else if(shu >= 10000)
            w = 5;
        else
            w = 1;
        shu = shu>=10000 ? shu-10000 : shu;
        a[cnt].val = shu;
        a[cnt].w = w;
        cnt++;
    }
    int ans = DP(cnt);
    printf("%d\n", ans);
    return 0;
}





/* #include<iostream>
#include<cstring>
using namespace std;
const int maxn = 50001;
int binary_search(int key, int *g, int low, int high)
{
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (key >= g[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
int main()
{
    int i, j, a[maxn], g[maxn], n, len;
    while (cin >> n)
    {
        memset(g, 0, sizeof(g));
        for (i = 0; i < n; i++)
            cin >> a[i];
        g[1] = a[0], len = 1;//初始化子序列长度为1，最小右边界
        for (i = 1; i < n; i++)
        {
            if (g[len] < a[i])//(如果允许子序列相邻元素相同 g[len]<=a[i],默认为不等）
                j = ++len; //a[i]>g[len],直接加入到g的末尾,且len++
            else
                j = binary_search(a[i], g, 1, len + 1);
            g[j] = a[i];//二分查找,找到第一个比a[i]小的数g[k],并g[k+1]=a[i]
        }
        cout << len << endl;
    }
    return 0;
} */