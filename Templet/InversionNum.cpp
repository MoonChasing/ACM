#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1000000;
int A[MAXN], T[MAXN];

int merge_cnt(int l, int r)
{
    int cnt = 0;

    if(r - l > 1)
    {
        int mid = l+r>>1;
        cnt += merge_cnt(l, mid);
        cnt += merge_cnt(mid, r);

        int p=l, q=mid, i=l;
        while(p<mid || q<r)
        {
            if(q>=r || (p<mid && A[p]<=A[q]))
            {
                T[i++] = A[p++];
            }
            else
            {
                T[i++] = A[q++];
                cnt += mid - p;
            }
        }

        for(i=l; i<r; i++)
            A[i] = T[i];
    }

    return cnt;

}


int merge_count(vector<int> &a)
{
    int n = a.size();
    if(n<=1)
        return 0;

    int cnt = 0;
    vector<int> b(a.begin(), a.begin()+n/2);
    vector<int> c(a.begin()+n/2, a.end());

    cnt += merge_count(b);
    cnt += merge_count(c);

    int ai=0, bi=0, ci=0;
    while(ai < n)
    {
        if(bi < b.size() && (ci==c.size() || b[bi]<=c[ci]) )
        {
            a[ai++] = b[bi++];
        }
        else
        {
            cnt += n/2-bi;
            a[ai++] = c[ci++];
        }

    }

    return cnt;
}

int main()
{
    srand((unsigned int)time(0));
    for(int i=0; i<MAXN; i++)
        A[i] = rand();
    vector<int> cika(A, A+MAXN);
    int s = clock();
    cout << "白书代码所得逆序对数:" << merge_count(cika) << endl;
    cout << "白书代码用时" << clock()-s << "ms" << endl;
    s = clock();
    cout << "白书代码所得逆序对数:" << merge_cnt(0, MAXN) << endl;
    cout << "紫书代码用时" << clock()-s << "ms" << endl;
    return 0;
}



















