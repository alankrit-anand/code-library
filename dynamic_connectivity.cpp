struct persistent_dsu{

    vi p, sz;
    stack<vi> st;
    int n, component;

    persistent_dsu(int _n){
        n = _n + 5;
        component = _n;
        p.resize(n);
        sz.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int u) {
        return u == p[u] ? u : find(p[u]);
    }

    bool join(int u, int v) {
        u = find(u), v = find(v);
        if(u == v)
            return 0;
        if(sz[u] > sz[v])
            swap(u, v);
        p[u] = v;
        sz[v] += sz[u];
        st.push({u, v, 0});
        component--;
        return 1;
    }

    void rollback(){

        while(sz(st) && st.top()[2] == 0){
            int u = st.top()[0], v = st.top()[1];
            p[u] = u;
            sz[v] -= sz[u];
            component++;
            st.pop();
        }

        if(sz(st)){
            st.top()[2]--;
        }

    }

    void check_point(){
        if(sz(st)){
            st.top()[2]++;
        }
    }
  
};


// twice the number of queries 
const int N = 6e5 + 5;

char op[N];
int u[N], v[N], other_end[N], res[N];


void calc(int tl, int tr, persistent_dsu &d)
{
    if(tl == tr)
    {
        res[tl] = d.component;
        return;
    }

    int tm = (tl + tr) / 2;

    {
        d.check_point();

        rep(i, tm, tr)
        {
            if(other_end[i] <= tl)
            {
                d.join(u[i], v[i]);
            }
        }

        calc(tl, tm, d);
        d.rollback(); 
    }

    {
        d.check_point();

        fr(i, tl + 1, tm + 1)
        {
            if(other_end[i] >= tr)
            {
                d.join(u[i], v[i]);
            }
        }

        calc(tm + 1, tr, d);
        d.rollback(); 
    }
}


void solve()
{
    
    int n, k;
    cin >> n >> k;

    map<pii, int> mp;

    fr(i,1,k)
    {
        cin >> op[i];

        if(op[i] == '?')
            continue;

        cin >> u[i] >> v[i];

        if(u[i] > v[i])
            swap(u[i], v[i]);

        if(mp.count({u[i], v[i]}))
        {
            int j = mp[{u[i], v[i]}];
            other_end[i] = j;
            other_end[j] = i;
            mp.erase({u[i], v[i]});
        }
        else
        {
            mp[{u[i], v[i]}] = i;
        }
    }


    int idx = k;

    trav(t, mp)
    {
        other_end[t.se] = ++idx;
        other_end[idx] = t.se;
        u[idx] = t.fi.fi;
        v[idx] = t.fi.se;
    }

    
    persistent_dsu d(n);
    calc(1, idx + 1, d);


    fr(i,1,k)
    {
        if(op[i] == '?')
        {
            cout << res[i] << endl;
        }
    }

}