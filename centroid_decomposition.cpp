int sz[N];

int find_size(int v, int par){

    sz[v] = 1;
    trav(to, g[v]){
        if(to != par){
            sz[v] += find_size(to, v);
        }
    }
    return sz[v];
}

int find_centroid(int v, int par, int szz){

    trav(to, g[v]){
        if(to != par && sz[to] > szz / 2){
            return find_centroid(to, v, szz);
        }
    }
    return v;
}


void init_centroid(int v){

    int sz = find_size(v, 0);
    int c = find_centroid(v, 0, sz);

    trav(to, g[c]){
        dfs(to, c, c);
    }

    trav(to, g[c]){
        g[to].erase(c);
        init_centroid(to);
    }

    g[c].clear();
}