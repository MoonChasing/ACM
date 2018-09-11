#include <bits/stdc++.h>
using namespace std;
#define LL                long long
#define MOD             1000000007
#define mod(x)            (x%MOD)
#define CLR(a,x)        memset(a,x,sizeof(a))
#define FILL(a,n,x)     fill(a,a+n,x)
#define INF             0x3fffffff
#define INFL            0x3f3f3f3f3f3f3f3f
#define rep( i, l, r )     for( int i = l; i <= r; ++i )
#define fastio()        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

struct node {
    int dimension = 4;
    LL matrix[4][4];
    node operator*( node n ) {
        node n2;
        for( int i = 0; i < dimension; ++i ) {
            for( int j = 0; j < dimension; ++j ) {
                n2.matrix[i][j]  = 0;
                for( int k = 0; k < dimension; ++k ) {
                    n2.matrix[i][j] = ( n2.matrix[i][j] + matrix[i][k] * n.matrix[k][j] %MOD) % MOD;
                }
            }
        }
        return n2;
    }
    void init() {
        for( int i = 0; i < dimension; ++i ) {
            for( int j = 0; j < dimension; ++j ) {
                matrix[i][j] = 0;
            }
        }
        for( int i = 0; i < dimension; ++i ) {
            matrix[i][i] = 1;
        }
    }
    node() {}
    node( const node& n ) {
        for( int i = 0; i < dimension; ++i ) {
            for( int j = 0; j < dimension; ++j ) {
                matrix[i][j] = n.matrix[i][j];
            }
        }
    }
    node( LL a[][4] ) {
        for( int i = 0; i < dimension; ++i ) {
            for( int j = 0; j < dimension; ++j ) {
                matrix[i][j] = a[i][j];
            }
        }
    }
};

node quick_mul( node n1, LL n ) {
    node base = n1;
    node res;
    res.init();
    while( n ) {
        if( (n&1) ) {
            res = res * base;
        }
        base = base * base;
        n >>= 1;
    }
    return res;
}

LL A, B, C, D, P, n;

LL getF( LL st ) {
    if( ( P/(st-1) == 1 || st == 3 ) && st > P ) {
        return n;
    }
    return min( 0LL+st+(P%st)/(P/st), 0LL+n );
}

LL tmpp[4];
LL st, f;
LL nn[4];

int main() {
    fastio();

    int _;
    scanf( "%d", &_ );
    while( _-- ) {
        scanf( "%lld%lld%lld%lld%lld%lld", &A, &B, &C, &D, &P, &n );

        if( n == 1 || n == 2 ) {
            if( n == 1 ) {
                printf( "%lld\n", A );
            } else {
                printf( "%lld\n", B );
            }
            continue;
        }


        f = 2;
        nn[1] = B, nn[2] = A;
        nn[3] = P/3;
        nn[0] = C * A + D * B + nn[3];
        //cout<<nn[0]<<" "<<nn[1]<<" "<<nn[2]<<" "<<nn[3]<<endl;
        while( true ) {
            st = f + 1;
            f = getF( st );
            if( f >= n )
            {
                LL tmp[][4] = {
                    {
                         D, C, 0, 1
                    },
                    {
                        1, 0, 0, 0
                    },
                    {
                        0, 1, 0, 0
                    },
                    {
                        0, 0, 0, 1
                    }
                };
                node n1(tmp);
                n1 = quick_mul( n1, n-st );
                //n1.show();
                rep( i, 0, 3 ) {
                    tmpp[i] = 0;
                    rep( j, 0, 3 ) {
                        tmpp[i] = ( tmpp[i] + nn[j] * n1.matrix[i][j]%MOD ) % MOD;
                    }
                }
                rep( i, 0, 3 ) {
                    nn[i] = tmpp[i];
                }
                printf( "%lld\n", nn[0] );
                break;
            }
            else
            {
                LL tmp[][4] = {
                    {
                         D, C, 0, 1
                    },
                    {
                        1, 0, 0, 0
                    },
                    {
                        0, 1, 0, 0
                    },
                    {
                        0, 0, 0, 1
                    }
                };
                node n1(tmp);
                n1 = quick_mul( n1, f-st );

                rep( i, 0, 3 ) {
                    tmpp[i] = 0;
                    rep( j, 0, 3 ) {
                        tmpp[i] = ( tmpp[i] + ( nn[j] * n1.matrix[i][j] ) % MOD ) % MOD;
                    }
                }
                rep( i, 0, 3 ) {
                    nn[i] = tmpp[i];
                }
                tmpp[0] = ( C * nn[1]%MOD + D * nn[0] %MOD+ P/(f+1) ) % MOD;
                tmpp[1] = nn[0];
                tmpp[2] = nn[1];
                tmpp[3] = nn[2];
                rep( i, 0, 3 ) {
                    nn[i] = tmpp[i];
                }

                rep( i, 0, 3 ) {
                    nn[i] = tmpp[i];
                }
                nn[3] = P/(f+1);
            }
        }
    }


    return 0;
}
