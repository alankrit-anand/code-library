struct centroid{

    int n;
    vi sz;
    vvi g;

    centroid() {}
    centroid(graph &d){
        n = d.n;
        sz.resize(n + 1);
        g = d.g;
    }

    void dfs(int v, int p){
        sz[v] = 1;
        trav(to, g[v]){
            if(to != p){
                dfs(to, v);
                sz[v] += sz[to];
            }
        }
    }

    int dfs1(int v, int p){
        
        int largest_child = -1;
        trav(to, g[v]){
            if(to != p){
                if(largest_child == -1 || sz[to] > sz[largest_child]){
                    largest_child = to;
                }
            }
        }

        return sz[largest_child] > n / 2 ? dfs1(largest_child, v) : v;
    }


    int solve(){
        dfs(1, -1);
        return n == 1 ? 1 : dfs1(1, -1);
    }
};