int inv(vi a)
{
    int res = 0;

    ordered_multiset<int> s;

    for(int x : a)
    {
        int pos = s.order_of_key(x);
        res += sz(s) - pos;
        s.insert(x);
    }

    return res;
}