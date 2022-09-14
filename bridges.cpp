struct bridges {

    int n, timer = 0;
    vi tin, fup;
    vvi g;
    vector<bool> used;
    map<pii, bool> is_bridge;
    
    bridges(int _n) {
        n = _n;
        tin.resize(n);
        fup.resize(n);
        used.resize(n);
        g.resize(n);
    }

    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
        is_bridge[{u, v}] = is_bridge[{v, u}] = 0;
    }


    void dfs(int v, int p) {
        used[v] = 1;
        tin[v] = fup[v] = timer++;

        trav(to, g[v]) {
            if (to == p) 
                continue;
            if (used[to]) {
                fup[v] = min(fup[v], tin[to]);
            } else {
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
                if (fup[to] > tin[v]){
                    is_bridge[{v, to}] = is_bridge[{to, v}] = 1;
                }
            }
        }
    }

    void solve(){
        rep(i, 0, n){
            if(!used[i]){
                dfs(i, -1);
            }
        }
    }
    
    
};