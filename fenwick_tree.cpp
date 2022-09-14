struct fenwick{

    int n;
    vi bit;

    fenwick(int _n){
        n = _n + 5;
        bit.resize(n);
    }

    int qry(int i){
        int res = 0;
        for(++i; i; i -= i & - i)
            res += bit[i];
        return res;
    }

    void upd(int i, int val){
        for(++i; i < n; i += i & -i)
            bit[i] += val;
    }
};