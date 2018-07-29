#include <bits/stdc++.h>

using namespace std;

int A[10] = {3, 6, 2, 1, 4, 5, 6, 7, 12, 10};
int T[10];

void mergesort(int l, int r)
{
    if(r-l > 1)
    {
        int mid = l+r>>1;

        mergesort(l, mid);
        mergesort(mid, r);

        int p=l, q=mid, i=l;

        while(p < mid || q < r)
        {
            if( q>=r || ( p<mid && A[p] <= A[q] ) )
                T[i++] = A[p++];
            else
                T[i++] = A[q++];
        }

        for(int i=l; i<r; i++)
            A[i] = T[i];
    }
}

int main()
{
    mergesort(0, 10); //右端点应使用r+1，即最后一个元素后面的位置
    for(int i=0; i<10; i++)
        printf("%-3d", A[i]);
    return 0;
}
