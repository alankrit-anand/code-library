vi dijkstra(int src, int n)
{
    vi d(n + 1, infl);

    spii s;
    d[src] = 0;
    s.insert({d[src], src});

    while(sz(s))
    {
        auto [dis, v] = *s.begin();
        s.erase(s.begin());

        if(dis > d[v])
            continue;

        for(auto [to, w] : g[v])
        {
            int new_dis = dis + w;

            if(new_dis < d[to])
            {
                d[to] = new_dis;
                s.insert({d[to], to});
            }
        }
    }

    return d;
}