struct bipartite_matcher{

    vvi g;
    vi l, r, viz;

    bipartite_matcher(int n, int m){
        g.resize(n);
        l.resize(n, -1);
        r.resize(m, -1);
        viz.resize(n);
    }


    void add_edge(int u, int v){
        g[u].pb(v); 
    }

    bool match(int v){

        if(viz[v]) 
            return 0;

        viz[v] = 1;
        trav(to, g[v]){
            if(r[to] == -1 || match(r[to])) {
                l[v] = to;
                r[to] = v;
                return 1;
            }
        }

        return 0;
    }

    int solve(){

        bool ok = 1;

        while(ok){
            ok = 0;
            fill(all(viz), 0);
            rep(i, 0, sz(l)){
                if(l[i] == -1)
                    ok |= match(i);
            }
        }

        int ret = 0;
        rep(i, 0, sz(l))
            ret += (l[i] != -1);
            
        return ret;
    }

};