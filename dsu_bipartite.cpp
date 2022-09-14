struct dsu{

    vi p, sz, col;
    int n;
 
    dsu(int _n)
    {
        n = _n + 5;
        p.resize(n);
        sz.resize(n, 1);
        col.resize(n);
        iota(p.begin(), p.end(), 0);
    }
 
    int find(int u) 
    {
        return u == p[u] ? u : find(p[u]);
    }

    int get_col(int u)
    {
        if(u == p[u])
            return col[u];

        return col[u] ^ get_col(p[u]);
    }
 
    bool join(int u, int v, int x) 
    {
        int pu = find(u);
        int pv = find(v);
        int cu = get_col(u);
        int cv = get_col(v);

        if(pu == pv)
        {
            return cu == (cv ^ x);
        }

        if(sz[pu] > sz[pv])
        {
            swap(pu, pv);
        }

        p[pu] = pv;
        sz[pv] += sz[pu];

        if((cu ^ x) != cv)
        {
            col[pu] ^= 1;
        }
        
        return 1;
    }
};