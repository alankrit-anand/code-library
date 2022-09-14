struct dsu{

    vi p, sz;
    int n;
 
    dsu(int _n)
    {
        n = _n + 5;
        p.resize(n);
        sz.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }
 
    int find(int u) 
    {
        return u == p[u] ? u : (p[u] = find(p[u]));
    }
 
    bool join(int u, int v) 
    {
        u = find(u), v = find(v);

        if(u == v)
        {
            return 0;
        }

        if(sz[u] > sz[v])
        {
            swap(u, v);
        }

        p[u] = v;
        sz[v] += sz[u];
        
        return 1;
    }
};