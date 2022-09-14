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
