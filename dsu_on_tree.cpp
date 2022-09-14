int sz[N], col[N], cnt[N];
vi vec[N], g[N];


void dfs_size(int v, int p) {

    sz[v] = 1;

    trav(to, g[v]) {
        if (to != p) {
            dfs_size(to, v);
            sz[v] += sz[to];
        }
    }

}


void dfs(int v, int p, bool keep) {

    int mx = -1, bigchild = -1;

    trav(to, g[v]) {
        if (to != p && mx < sz[to]) {
            mx = sz[to];
            bigchild = to;
        }
    }
    
    trav(to, g[v]){
        if (to != p && to != bigchild) {
            dfs(to, v, 0);
        }
    }

    if (bigchild != -1) {
        dfs(bigchild, v, 1);
        swap(vec[v], vec[bigchild]);
    }

    vec[v].pb(v);
    cnt[col[v]]++;

    trav(to, g[v]){
        if (to != p && to != bigchild) {
            trav(x, vec[to]){
                cnt[col[x]]++;
                vec[v].pb(x);
            }
        }
    }

    // there are cnt[c] vertex in subtree v color with c

    if (keep == 0) {
        trav(x, vec[v]) {
            cnt[col[x]]--;
        }
    }
}