const int N = 2e5 + 5;

vi g[N];
int parent[N][20];
int tin[N], tout[N], dep[N];
int timer;


void dfs(int v, int p)
{
    parent[v][0] = p;
    tin[v] = ++timer;

    trav(to, g[v])
    {
        if(to != p)
        {
            dep[to] = dep[v] + 1;
            dfs(to, v);
        }  
    }

    tout[v] = ++timer;
}


void build_lca(int n)
{
    dfs(1, 1);

    rep(i,1,20)
    {
        fr(v, 1, n)
        {
            parent[v][i] = parent[parent[v][i-1]][i-1];
        }
    }
}


bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}


int lca(int u, int v)
{
    if (is_ancestor(u, v))
    {
        return u;
    }

    if (is_ancestor(v, u))
    {
        return v;
    }

    for (int i = 19; i >= 0; --i) 
    {
        if (!is_ancestor(parent[u][i], v))
        {
            u = parent[u][i];
        }
    }

    return parent[u][0];
}