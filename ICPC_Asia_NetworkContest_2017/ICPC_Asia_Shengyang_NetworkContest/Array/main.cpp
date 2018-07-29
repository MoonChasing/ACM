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
#define MAXN 100010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int arr[MAXN],ans[MAXN], ans2[MAXN],len, len2;

/*
    ���ֲ��ҡ� ע�⣬������ֲ��������½��;  (ʲô���½磿��������㷨���ž��䡷 P145)
    ������ >= �����Ҷ���ĵ�һ��λ�ã�����Ϊʲô��

    Ҳ������STL��lowe_bound���ֲ�������½�
*/
//����½�
int binary_search(int i)
{
    int left,right,mid;
    left=0,right=len;
    while(left<right)
    {
        mid = left+(right-left)/2;
        if(ans[mid]>arr[i]) right=mid;
        else left=mid+1;
    }
    return left;
}

//�������
int binary_search_2(int i)
{
    int left,right,mid;
    left=0,right=len;
    while(left<right)
    {
        mid = left+(right-left)/2;
        if(ans[mid]<arr[i]) right=mid;
        else left=mid+1;
    }
    return left;
}

int main()
{
    int T,n,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(i=1; i<=n; ++i)
            scanf("%d",&arr[i]);

        ans[1] = arr[1];
        ans2[1] = arr[1];
        len=1;
        len2 = 1;

        for(i=2; i<=n; ++i)
        {
            if(arr[i]>ans[len])
            {
                ans[++len]=arr[i];
            }
            else
            {
                int pos=binary_search(i);   // �����STL�� pos=lower_bound(ans,ans+len,arr[i])-ans;
                ans[pos] = arr[i];
            }

            if(arr[i] < ans2[len2])
            {
                ans2[++len2] = arr[i];
            }
            else
            {
                int pos= binary_search_2(i);
                ans2[pos] = arr[i];
            }

        }
        len2++;
        if(len+k>=n || len2+k>=n)
            puts("A is a magic array.");
        else
            puts("A is not a magic array.");
    }
    return 0;
}



