struct fenwick_tree_2D{
    vvi bit;
    int n, m;

    fenwick_tree_2D(int _n, int _m){
        n = _n, m = _m;
        bit.resize(n + 5, vi(m + 5));
    }

    int qry(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void upd(int x, int y, int delta) {
        for (int i = x; i <= n; i = i | (i + 1))
            for (int j = y; j <= m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};