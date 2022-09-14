struct cutpoints {

    int n, timer = 0;
    vi tin, fup;
    vvi g;
    vector<bool> used, is_cutpoint;

    cutpoints(int _n){
        n = _n;
        tin.resize(n);
        fup.resize(n);
        used.resize(n);
        g.resize(n);
        is_cutpoint.resize(n);
    }

    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
    }


    void dfs(int v, int p) {

        tin[v] = fup[v] = timer++;
        used[v] = 1;
        int cnt = 0;
        
        trav(to, g[v]){
            
            if (to == p) 
                continue;

            if (used[to]) {
                fup[v] = min(fup[v], tin[to]);
            } 
            else {
                cnt++;
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
                if (fup[to] >= tin[v] && p != -1)
                    is_cutpoint[v] = 1;
            }
        }
    
        if (p == -1 && cnt > 1)
            is_cutpoint[v] = 1;
    }

    void solve(){
        rep(i,0,n){
            if(!used[i]){
                dfs(i, -1);
            }
        }
    }
 
};