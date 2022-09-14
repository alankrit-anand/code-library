struct Set
{
    int n;
    vi pos;
    vi g;


    Set(int _n)
    {
        n = _n + 5;
        pos.resize(n, -1);
    }

    void insert(int i)
    {
        if(pos[i] != -1)
            return;

        pos[i] = sz(g);
        g.pb(i);
    }

    void erase(int i)
    {
        if(pos[i] == -1)
            return;

        pos[g.back()] = pos[i];
        g[pos[i]] = g.back();

        g.pop_back();
        pos[i] = -1;
    }
};