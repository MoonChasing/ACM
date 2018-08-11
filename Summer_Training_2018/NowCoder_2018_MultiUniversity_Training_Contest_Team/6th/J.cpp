#include<bits/stdc++.h>
using namespace std;
#define LL long long

int n;
unsigned x, y, z;
const int N = 100000;
unsigned A[N];

unsigned tang() {
	unsigned t;
	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;
	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;
	return z;
}

struct node {
    unsigned a, b, c;
    node() {}
    node( unsigned x, unsigned y, unsigned z ) {
        a = x, b = y, c = z;
    }
    int operator<( const node& n1 ) const {
        if( a != n1.a ) {
            return a > n1.a;
        } else if( b != n1.b ) {
            return b > n1.b;
        } else {
            return c > n1.c;
        }
    }
};

string change( unsigned a ) {
    string ans;
    while( a ) {
        if( a&1 ) {
            ans += '1';
        } else {
            ans += '0';
        }
        a >>= 1;
    }
//    while( ans.size() < 32 ) {
//        ans += '0';
//    }
    reverse( ans.begin(), ans.end() );
    return ans;
}




int main() {
	int _;
	scanf( "%d", &_ );
	while( _-- ) {
		scanf( "%d%u%u%u", &n, &x, &y, &z );
		unsigned a = 0;
		int id;
		map< node, int > M;
		for( int i = 0; i < n; ++i ) {
            cout<<change(x)<<"\t"<<change(y)<<"\t"<<change(z)<<endl;
			A[i] = tang();
			// cout<<A[i]<<" ";
            if( i >= 2 ) {
                node n1( x, y, z );
                if( M[n1] == 0 ) {
                    M[n1] += 1;
                } else {
                    cout<<i<<endl;
                }
            }
			// .puts("---------------------------");
			// cout<< x << " " << y <<  " " << z << endl;
			//cout<<A[i]<<" ";
			// puts("---------------------------");

		}
		// cout<<endl;
		//cout<<"finish"<<endl;
//		cout<<endl;
//		cout<<id<<endl;
//
		// cout<<1LL*A[0]*A[1]/__gcd( A[0], A[1] )<<endl;
		LL ans = -1;
		int u, v;
		for( int i = 0; i < n; ++i ) {
            for( int j = i+1; j < n; ++j ) {
                if( ans <= 1LL*A[i]*A[j]/__gcd( A[i], A[j] ) ) {
                    ans = 1LL*A[i]*A[j]/__gcd( A[i], A[j] );
                    u = i, v = j;
                }
            }
		}
		cout<<ans<<endl;
		cout<<u<<" "<<v<<endl;
	}
}
