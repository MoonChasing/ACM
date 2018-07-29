 
ll inv[maxn*2];   
void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y){if(!b){ x=1; y=0; d=a; }else{ex_gcd(b,a%b,d,y,x); y-=x*(a/b);}}  
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}  
ll exgcd(ll a,ll b,ll &x,ll &y){if(!b){x=1;y=0;return a;}ll ans=exgcd(b,a%b,x,y);ll temp=x;x=y;y=temp-a/b*y;return ans;}  
ll lcm(ll a,ll b){ return b/gcd(a,b)*a;}  
ll qpow(ll x,ll n){ll res=1;for(;n;n>>=1){if(n&1)res=(res*x)%MOD;x=(x*x)%MOD;}return res;}  
ll inv_exgcd(ll a,ll n){ll d,x,y;ex_gcd(a,n,d,x,y);return d==1?(x+n)%n:-1;}  
ll inv1(ll b){return b==1?1:(MOD-MOD/b)*inv1(MOD%b)%MOD;}  
ll inv2(ll b){return qpow(b,MOD-2);} 

/*
1.(a/b)%mod=a%(b*mod)/b%mod;(get这个公式好激动)
2.(a/b)%mod=a*b^(mod-2)%mod，mod为素数（可以通过逆元证明）
*/