struct strongly_connected_component {

    int n; 
    vvi g, gr;
    vi used, vs, cmp;
    int scc_num = 0;
 
    strongly_connected_component (int n = 0) : n(n), g(n + 1), gr(n + 1), cmp(n + 1) {}

    void add_edge(int u, int v){
        g[u].pb(v);
        gr[v].pb(u);
    }
 
    void dfs(int v) {
        used[v] = 1;
        trav(to, g[v]){
            if(!used[to]){
                dfs(to);
            }
        }
        vs.pb(v);
    }

    void rdfs(int v, int k) {
        used[v] = 1;
        cmp[v] = k;
        trav(to, gr[v]){
            if(!used[to]){
                rdfs(to, k);
            }
        }
    }
 
    // 1 based SCC indexing
    int find_strongly_connected_components() {
        used.assign(n + 1, false);
        fr(v, 1, n){
            if(!used[v]){
                dfs(v);
            }
        }
        used.assign(n + 1, false);
        frev(i, 0, sz(vs) - 1){
            if(!used[vs[i]]){
                rdfs(vs[i], ++scc_num);
            }
        }
        return scc_num;
    }
 
    // Call find_strongly_connected_components() before calling this
    strongly_connected_component generate_topological_graph() {
        strongly_connected_component newgraph(scc_num);
        fr(i,1,n){
            trav(to, g[i]){
                if(cmp[i] != cmp[to]){
                    newgraph.add_edge(cmp[i], cmp[to]);
                }
            }
        }
        return newgraph;
    }
};