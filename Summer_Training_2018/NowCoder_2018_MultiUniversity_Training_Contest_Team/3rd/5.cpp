#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 1e6+7;
char A[N];
int nexts[N];
int len;

void kmp_pre( char x[], int m, int nexts[] ) {
	int i, j;
	j = nexts[0] = -1;
	i = 0;
	while( i < m ) {
		while( -1 != j && x[i] != x[j] ) {
			j = nexts[j];
		}
		nexts[++i] = ++j;
	}
}

int main() {
    // freopen( "5.in", "r", stdin );
	scanf( "%s", A );
	len = strlen( A );
	kmp_pre( A, len, nexts );
	int cycle;
	if( len%(len-nexts[len]) == 0 ) {
		cycle = len / ( len - nexts[len] );
	} else {
		cycle = 1;
	}
	printf( "%d\n", len/cycle );
	for( int i = 0; i < len/cycle; ++i ) {
		printf( "%d", cycle );
		for( int j = 0; j < cycle; ++j ) {
			printf( " %d", (int)(i+j*(len/cycle)) );
		}
		puts( "" );
	}
}
