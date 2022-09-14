vi topological_sort(int n)
{
    qi q;
    vi indeg(n + 1);
    vi order;

    fr(i,1,n)
    {
        for(int to : g[i])
        {
            indeg[to]++;
        }
    }

    fr(i,1,n)
    {
        if(!indeg[i])
        {
            q.push(i);
        }
    }

    while(sz(q))
    {
        int v = q.front();
        q.pop();
        order.pb(v);

        for(int to : g[v])
        {
            indeg[to]--;

            if(!indeg[to])
            {
                q.push(to);
            }
        }
    }

    return order;
}
