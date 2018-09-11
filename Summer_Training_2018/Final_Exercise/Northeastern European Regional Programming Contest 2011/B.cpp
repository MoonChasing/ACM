#include <bits/stdc++.h>
#include     <algorithm>
#include      <iostream>
#include       <cstdlib>
#include       <cstring>
#include        <cstdio>
#include        <string>
#include        <vector>
#include         <stack>
#include         <cmath>
#include           <map>
using namespace std;
#define LL			    long long
#define MOD 		    1000000007
#define mod(x)		    (x%MOD)
#define CLR(a,x)        memset(a,x,sizeof(a))
#define FILL(a,n,x)     fill(a,a+n,x)
#define INF 		    0x3fffffff
#define INFL            0x3f3f3f3f3f3f3f3f
#define pb 		        push_back
#define rep( i, l, r ) 	for( int i = (l); i <= (r); ++i )
#define fastio()        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

template <class Z>
inline Z max( Z a, Z b ) {
    if( a > b ) {
        return a;
    }
    return b;
}
template <class Z>
inline Z min( Z a, Z b ) {
    if( a > b ) {
        return b;
    }
    return a;
}

template <class T>
inline bool scand(T &ret) {
    char c;
    int sgn;
    if( c=getchar() , c==EOF ) return 0; //EOF
    while( c!='−' && ( c<'0' || c>'9' ) ) c=getchar();
    sgn = (c=='−') ? -1 : 1;
    ret = ( c == '−' ) ? 0 : (c-'0');
    while( c=getchar(), c>='0'&& c<='9' ) ret = ret*10+(c-'0');
    ret *= sgn;
    return 1;
}
inline void out(int x) {
    if( x < 0 ) {
        printf( "%d", x );
        return;
    }
    if(x>9) out(x/10);
    putchar(x%10+'0');
}

int n;
string getAns( int x, int n ) {
    string ans;
    while( x ) {
        if( x&1 ) {
            ans += '1';
        } else {
            ans += '0';
        }
        x >>= 1;
    }
    int size = ans.size();
    while( size < n ) {
        ans += '0';
        size += 1;
    }
    reverse( ans.begin(), ans.end() );

    return ans;
}

int pow( int a, int n ) {
    int ans = 1;
    int base = a;
    while( n ) {
        if( n&1 ) {
            ans *= base;
        }
        base *= base;
        n >>= 1;
    }
    return ans;
}

int main() {
    fastio();
    freopen( "binary.in", "r", stdin );
    freopen( "binary.out", "w", stdout );
    scand(n);
    int k = 0;
    int base = 1;
    while( true ) {
        if( base <= n && n < base*2 ) {
            break;
        }
        k += 1;
        base *= 2;
    }
    int u = pow(2,k+1)-n;
    rep( i, 0, u-1 ) {
        cout<<getAns(i,k)<<endl;
    }
    rep( i, 0, n-u-1 ) {
        cout<<"1";
        cout<<getAns(i,k)<<endl;
    }


    return 0;
}
