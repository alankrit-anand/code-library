template<class T1, class T2>
struct lazy_segment_tree 
{
    int n;
    vector<T1> t;
    vector<T2> lazy;
     
    lazy_segment_tree(int _n) 
    {
        n = _n;
        t.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
    }
    
    void push(int v, int tl, int tm, int tr) 
    {
        t[2*v] += (tm - tl + 1) * lazy[v];
        t[2*v+1] += (tr - tm) * lazy[v];
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
        lazy[v] = 0;
    }
   
    T1 combine(T1 x, T1 y)
    {
        return x + y;
    }

    void upd(int v, int tl, int tr, int l, int r, int val)
    {
        if(tl > r || tr < l)
        {
            return;
        }

        if(tl >= l && tr <= r)
        {
            t[v] += (tr - tl + 1) * val;
            lazy[v] += val;
            return;
        }

        int tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        upd(2*v, tl, tm, l, r, val);
        upd(2*v+1, tm+1, tr, l, r, val);
        t[v] = combine(t[2*v], t[2*v+1]);
    }

    T1 qry(int v, int tl, int tr, int l, int r)
    {
        if(tl > r || tr < l)
        {
            return 0;
        }

        if(tl >= l && tr <= r)
        {
            return t[v];
        }

        int tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        return combine(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
    }

    void upd(int l, int r, int val)
    {
        upd(1, 0, n, l, r, val);
    }

    T1 qry(int l, int r)
    {
        return qry(1, 0, n, l, r);
    }
     
};