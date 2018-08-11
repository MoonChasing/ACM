#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
struct node {
	int u, v, weight;
} A[N];

int n, m, k;
int cmp( node n1, node n2 ) {
	return n1.weight > n2.weight;
}
bool vis[N];

int main() {
	int _;
	scanf( "%d", &_ );
	int cases = 1;
	while( _-- ) {
		scanf( "%d%d%d", &n, &m, &k );
		for( int i = 0; i < k; ++i ) {
			scanf( "%d%d%d", &A[i].u, &A[i].v, &A[i].weight );
		}
		sort( A, A+k, cmp );
		memset( vis, false, sizeof(vis) );
		long long cnt = 0;
		for( int i = 0; i < k; ++i ) {
			int v = A[i].v;
			if( !vis[v] ) {
				cnt += A[i].weight;
				vis[v] = true;
			}
		}
		printf( "Case #%d: %lld\n", cases++, cnt );
	}
}

