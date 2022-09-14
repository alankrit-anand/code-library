template<class T>
struct segment_tree{

    int n;
    vector<T> t;

    segment_tree(int _n)
    {
        n = _n;
        t.resize(4 * n + 5);
    }

    T combine(T x, T y)
    {
        return x + y;
    }


    void upd(int v, int tl, int tr, int pos, int val)
    {
        if(tl == tr)
        {
            t[v] = val;
            return;
        }

        int tm = (tl + tr) / 2;

        if(pos <= tm)
            upd(2*v, tl, tm, pos, val);
        else
            upd(2*v+1, tm+1, tr, pos, val);

        t[v] = combine(t[2*v], t[2*v+1]);
    }

    T qry(int v, int tl, int tr, int l, int r){

        if(tl > r || tr < l)
            return 0;

        if(tl >= l && tr <= r)
            return t[v];

        int tm = (tl + tr) / 2;
        return combine(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
    }

    void upd(int pos, int val)
    {
        upd(1, 0, n, pos, val);
    }

    T qry(int l, int r)
    {
        return qry(1, 0, n, l, r);
    }

};