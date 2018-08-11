#include<bits/stdc++.h>
using namespace std;

int n;
int songs[(1<<14)+7][14+7];
bool vis[(1<<14)+7][14+7];
int ids[(1<<14)+7];

bool win( int index1, int index2 ) {
	int maxs1, maxs2;
	int ids1, ids2;
	for( int i = n-1; i >= 0; --i ) {
		if( !vis[index1][i] ) {
			maxs1 = songs[index1][i];
			ids1 = i;
			break;
		}
	}
	for( int i = n-1; i >= 0; --i ) {
		if( !vis[index2][i] ) {
			maxs2 = songs[index2][i];
			ids2 = i;
			break;
		}
	}
	if( maxs1 > maxs2 ) {
		int id = ids1;
		for( int i = n-1; i >= 0; --i ) {
			if( !vis[index1][i] ) {
				if( songs[index1][i] < maxs2 ) {
					break;
				}
				id = i;
			}
		}
		vis[index1][id] = true;
		return true;
	} else {
		int id = ids2;
		for( int i = n-1; i >= 0; --i ) {
			if( !vis[index2][i] ) {
				if( songs[index2][i] < maxs1 ) {
					break;
				}
				id = i;
			}
		}
		vis[index2][id] = true;
		return false;
	}
}

int main() {
	int _;
	scanf( "%d", &_ );
	int cases = 1;
	while( _-- ) {
		scanf( "%d", &n );
		for( int i = 0; i < (1<<n); ++i ) {
			for( int j = 0; j < n; ++j ) {
				scanf( "%d", &songs[i][j] );
			}
			sort( songs[i], songs[i]+n );
		}
		int nn = ( 1<<n );
		// CLR( vis, false );
		memset( vis, false, sizeof(vis) );
		for( int i = 0; i < nn; ++i ) {
            ids[i] = i;
		}
		while( true ) {
			for( int i = 0; i < nn; i += 2 ) {
				if( win( ids[i], ids[i+1] ) ) {
					ids[i/2] = ids[i];
				} else {
					ids[i/2] = ids[i+1];
				}
			}
			nn /= 2;
			if( nn == 1 ) {
				break;
			}
		}
		printf( "Case #%d: %d\n", cases++, ids[0]+1 );
	}
}
