#include<bits/stdc++.h>
using namespace std;
int num[100000+5];
int main(){

    int n, m;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int sum = 0;
        for(int i = 0;i < n;i++){
            scanf("%d",&num[i]);
            sum ^= num[i];
        }
        for(int i = 0;i < n-1;i++){
            scanf("%d",&m);
            scanf("%d",&m);
        }
        if(sum)
            puts("Q");
        else
            puts("D");
    }
}
