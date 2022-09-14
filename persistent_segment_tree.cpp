struct node{
    node *l, *r;
    int sum;
    node(int val) : l(nullptr), r(nullptr), sum(val) {}
    node(node *l, node *r) : l(l), r(r), sum((l ? l->sum : 0) + (r ? r->sum : 0)) {}
};


struct persistent_segment_tree{

    int n, q, cur = 0;
    vector<node*> version;

    persistent_segment_tree(int _n, int _q, vi &a){
        n = _n, q = _q;
        version.resize(q + 5);
        version[cur++] = build(a, 0, n);
    }

    node* build(vi &a, int tl, int tr){
        if(tl == tr){
            return new node(a[tl]);
        }
        int tm = (tl + tr) / 2;
        return new node(build(a, tl, tm), build(a, tm+1, tr));
    }

    node* upd(node *v, int tl, int tr, int pos, int val){
        if(tl == tr)
            return new node(val);
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            return new node(upd(v->l, tl, tm, pos, val), v->r);
        return new node(v->l, upd(v->r, tm+1, tr, pos, val));
    }

    int qry(node *v, int tl, int tr, int l, int r){
        if(tl > r || tr < l)
            return 0;
        if(tl >= l && tr <= r)
            return v->sum;
        int tm = (tl + tr) / 2;
        return qry(v->l, tl, tm, l, r) + qry(v->r, tm+1, tr, l, r);
    }

    void upd(int idx, int pos, int val){
        version[cur++] = upd(version[idx], 0, n, pos, val);
    }

    int qry(int idx, int l, int r){
        return qry(version[idx], 0, n, l, r);
    }

};
