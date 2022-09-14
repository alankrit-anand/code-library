int powm(int a, int b, int mod)
{
    int res = 1;

    while(b) 
    {
        if(b & 1)
        {
            res = res * a % mod;
        }

        a = a * a % mod;
        b /= 2;
    }

    return res;
}

struct string_hash{

    string s;
    int n, b1, b2;
    vpii hsh;
    vpii pw; 

    string_hash(string _s)
    {
        s = _s;
        n = sz(s);
        hsh.resize(n + 1);
        pw.resize(n + 1);
        b1 = rng(mt);
        b2 = rng(mt);

        fr(i,1,n)
        {
            hsh[i].fi = (hsh[i-1].fi * b1 + (s[i-1] - 'a' + 1)) % mod1;
            hsh[i].se = (hsh[i-1].se * b2 + (s[i-1] - 'a' + 1)) % mod2;
        }

        pw[0] = {1, 1};

        fr(i,1,n)
        {
            pw[i].fi = pw[i-1].fi * b1 % mod1;
            pw[i].se = pw[i-1].se * b2 % mod2;
        }
    }

    pii get_hash(int i, int j){
 
        pii h;
        int len = j - i + 1;
 
        h.fi = ((hsh[j + 1].fi - hsh[i].fi * pw[len].fi) % mod1 + mod1) % mod1;
        h.se = ((hsh[j + 1].se - hsh[i].se * pw[len].se) % mod2 + mod2) % mod2;
 
        return h;
    }

};