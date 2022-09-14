int fact[N], inv_fact[N];

int powm(int a, int b){
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void pre(){

    fact[0] = 1;
    rep(i,1,N)
        fact[i] = fact[i-1] * i % mod;

    inv_fact[N - 1] = powm(fact[N - 1], mod - 2);
    frev(i,0,N-2)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;

}

int nCr(int x, int y){
    if(x < y)
        return 0;
    return fact[x] * inv_fact[y] % mod * inv_fact[x - y] % mod;
}








