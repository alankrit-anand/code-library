// 1-based

ordered_set<int> s[N];

void add(int x, int y)
{
    while(x < N)
    {
        s[x].insert(y);
        x += x & -x;
    }
}


void rem(int x, int y)
{
    while(x < N)
    {
        s[x].erase(y);
        x += x & -x;
    }
}


int qry(int l1, int r1, int l2, int r2)
{
    int ans = 0;
    l1--;

    while(l1 > 0)
    {
        ans -= s[l1].order_of_key(r2 + 1) - s[l1].order_of_key(l2);
        l1 -= l1 & -l1;
    }

    while(r1 > 0)
    {
        ans += s[r1].order_of_key(r2 + 1) - s[r1].order_of_key(l2);
        r1 -= r1 & -r1;
    }

    return ans;
}
