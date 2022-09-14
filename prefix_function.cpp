vi prefix_function(string s) 
{
    int n = sz(s);
    vi pi(n);

    rep(i,1,n) 
    {
        int j = pi[i-1];

        while (j > 0 && s[i] != s[j])
        {
            j = pi[j-1];
        }

        if (s[i] == s[j])
        {
            j++;
        }

        pi[i] = j;
    }
    
    return pi;
}



vvi compute_automaton(string s) 
{
    s += '#';
    int n = sz(s);

    vvi aut(n, vi(26));
    vi pi = prefix_function(s);

    rep(i,0,n)
    {
        rep(c,0,26)
        {
            if(i && 'a' + c != s[i])
            {
                aut[i][c] = aut[pi[i-1]][c];
            }
            else
            {
                aut[i][c] = i + ('a' + c == s[i]);
            }
        }
    }

    return aut;
}