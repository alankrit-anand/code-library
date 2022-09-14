struct mint {
    int x;
    mint() : x(0) {}
    mint(int x) : x((x % mod + mod) % mod) {}
    mint operator -() const { return mint(0) - *this;}
    mint operator ~() const { return mint(1) / *this;}
    mint& operator +=(const mint& a) { if((x += a.x) >= mod) x -= mod; return *this;}
    mint& operator -=(const mint& a) { if((x += mod - a.x) >= mod) x -= mod; return *this;}
    mint& operator *=(const mint& a) { x = x * a.x % mod; return *this;}
    mint& operator /=(const mint& a) { x = x * a.pow(mod-2).x % mod; return *this;}
    mint operator +(const mint& a) const { return mint(*this) += a;}
    mint operator -(const mint& a) const { return mint(*this) -= a;}
    mint operator *(const mint& a) const { return mint(*this) *= a;}
    mint operator /(const mint& a) const { return mint(*this) /= a;}
    mint pow(int t) const { mint ret(1), pw = mint(*this); while(t){ if(t & 1) ret *= pw; pw *= pw; t /= 2;} return ret;}
    bool operator <(const mint& a) const { return x < a.x;}
    bool operator ==(const mint& a) const { return x == a.x;}
    bool operator !=(const mint& a) const { return x != a.x;}
    friend istream& operator >>(istream& is, mint& p) { return is >> p.x; }
    friend ostream& operator <<(ostream& os, mint p){ return os << p.x; }
};

const int N = 2e6 + 5;
 
mint fact[N], inv_fact[N];
 
void pre(){
 
    fact[0] = 1;
    rep(i,1,N)
        fact[i] = fact[i-1] * i;
 
    inv_fact[N - 1] =  ~fact[N - 1];
    frev(i,0,N-2)
        inv_fact[i] = inv_fact[i + 1] * (i + 1);
 
}
 
mint nCr(int x, int y){
    if(x < y)
        return 0;
    return fact[x] * inv_fact[y] * inv_fact[x - y];
}