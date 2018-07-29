#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num;

//    cout << tolower('A') << endl;
//    while(~scanf("%d", &num))
//    {
//        printf("%d\n", num & -num);
//        cout << log10(num & -num)/log10(2) << endl;
//        cout << __builtin_ffs(num) << endl;
//        cout << __builtin_ctz(num) << endl;
//    }

    int arr[] = {5,5464,54,6,231,54,31};
    vector<int> a(arr, arr+7);
    //sort(a.rbegin(), a.rend());
    sort(a.begin(), a.end(), less<int>() );
    for(vector<int>::iterator it = a.begin(); it != a.end(); it++)
    cout << *it << endl;
    return 0;
}
