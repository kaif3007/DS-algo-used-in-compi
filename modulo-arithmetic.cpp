#define ll long long int
#define MOD 1000000007

ll add(ll x,ll y)
{
    x += y;
    while(x >= MOD) 
        x -= MOD;
    while(x < 0) 
       x += MOD;
    return x;
}
 
ll mul(ll x,ll y)
{
    return ((x%MOD)*(y%MOD)) % MOD;
}
 
ll binpow(ll x,ll y)
{
    ll z = 1;
    while(y)
    {
        if(y & 1)
         z = mul(z, x);
     
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
 
ll inv(ll x)
{
    return binpow(x, MOD - 2);
}
 
 
ll divide(ll x,ll y)
{
    return mul(x, inv(y));
}
