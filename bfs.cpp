vi bfs(int src, int n)
{
    vi d(n + 1, infl);

    qi q;
    d[src] = 0;
    q.push(src);

    while(sz(q))
    {
        int v = q.front();
        q.pop();

        for(int to : g[v])
        {
            if(d[to] == infl)
            {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }

    return d;
}