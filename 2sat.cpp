struct sat2{

    int n;
    vvi g, gt;
    vi used, order, comp, assignment;

    sat2(int _n){
        n = _n;
        used.assign(2*n, 0);
        comp.assign(2*n, -1);
        assignment.assign(n, 0);
        g.resize(2*n);
        gt.resize(2*n);
    }

    void dfs1(int v) {
        used[v] = 1;
        for(int u : g[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : gt[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve() {

        for (int i = 0; i < 2*n; ++i) {
            if (!used[i])
                dfs1(i);
        }

        for (int i = 0, j = 0; i < 2*n; ++i) {
            int v = order[2*n - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        for (int i = 0; i < 2*n; i += 2) {
            if (comp[i] == comp[i + 1])
                return 0;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }

        return 1;
    }

    void insert_edge(int u, int v){
        g[u].pb(v);
        gt[v].pb(u);
    }

    void add(int u, bool b1, int v, bool b2){
        insert_edge(2*u + b1, 2*v + !b2);
        insert_edge(2*v + b2, 2*u + !b1);
    }
};