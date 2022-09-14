struct MinCostFlow 
{
    typedef int capacity_t;
    typedef int cost_t;
 
    const cost_t INF = 1e9;
    const capacity_t MAX_CAP = 1e9;
 
    struct edge 
    {
        int from, v;
        capacity_t cap, flow;
        cost_t cost, dist;
        int rev_index;
        
        bool residual() { return flow < cap; }
        
        edge(int _f, int _v, capacity_t _cap, cost_t _cost):
            from(_f), v(_v), cap(_cap), flow(0), cost(_cost), dist(_cost) {}
    };
 
    int n, s, t;
    vector<cost_t> d;
    vector<edge*> p;
    vector<vector<edge>> g;
    vector<bool> queued;
    
    MinCostFlow(int n): n(n), d(n), p(n), g(n), queued(n) {}
    
    void bellman() 
    {
        rep(i,0,n) 
        { 
        	d[i] = INF; 
        	queued[i] = 0; 
        }
 
        queue <int> q;
        
        d[s] = 0;
        q.push(s); 
        queued[s] = 0;
        
        while (sz(q)) 
        {
            int u = q.front();
            q.pop(); 
            queued[u] = 0;
            
            for (auto &i : g[u])
            {
            	if (i.residual() && d[i.v] > d[u] + i.dist) 
            	{
                	d[i.v] = d[u] + i.dist;
                	p[i.v] = &i;
 
                	if(!queued[i.v]) 
                	{ 
                		q.push(i.v);
                		queued[i.v] = 1; 
                	}
            	}
            }    
        }
    }
 
    pair<capacity_t,cost_t> flow(int s, int t) 
    {
        this->s = s;
        this->t = t;
 
        capacity_t flow = 0;
        cost_t cost = 0;
 
        while (true) 
        {
            bellman();
 
            if (d[t] == INF) 
            	break;
 
            cost_t c = 0;
            capacity_t f = MAX_CAP;
            
            for (int u = t; u != s; u = (p[u] -> from)) 
            {
                f = min(f, (p[u] -> cap) - (p[u] -> flow));
            }
            
            for (int u = t; u != s; u = (p[u] -> from)) 
            {
                (p[u] -> flow) += f;
                g[p[u] -> v][p[u] -> rev_index].flow -= f;
                c += (p[u] -> cost);
            }
            
            flow += f; 
            cost += f * c;
        }
        
        return {flow, cost};
    }
    
    void addEdge(int a, int b, capacity_t f, cost_t c)
    {
        g[a].pb(edge(a, b, f, c));
        g[b].pb(edge(b, a, 0, -c));
        g[a].back().rev_index = sz(g[b]) - 1;
        g[b].back().rev_index = sz(g[a]) - 1;
    }
};