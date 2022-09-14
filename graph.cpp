struct graph{

    int n;
    vvi g;

    graph() {}
    graph(int n) : n(n), g(n+1), {}

    void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
    }


    void dfs(int v, int p){

        trav(to, g[v]){

            if(to != p){

                dfs(to, v);
            }
        }
    }
};