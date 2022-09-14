vi manacher_odd(string s) 
{
    int n = sz(s);
    s = "$" + s + "^";

    vi p(n + 2);
    int l = 1, r = 1;
 
    fr(i, 1, n) 
    {
        p[i] = max(0ll, min(r - i, p[l + (r - i)]));
 
        while(s[i - p[i]] == s[i + p[i]]) 
        {
            p[i]++;
        }
 
        if(i + p[i] > r) 
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
 
    return vi(p.begin() + 1, p.end() - 1);
}
 
 
vi manacher(vi s) 
{
    string t;
 
    trav(c, s)
    {
        t += '#';
        t += c;
    }
 
    t += '#';
 
    vi res = manacher_odd(t);
 
    return vi(res.begin() + 1, res.end() - 1);
}