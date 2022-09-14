// K = 2 for binary string
const int K = 26;

struct node
{
    int next[K];
    bool leaf;
    node() : leaf(0) { fill(begin(next), end(next), -1); }
};

struct Trie{

    vector<node> t;
    vi szz;

    Trie() : t(1), szz(1) {} 
    
    int get_size(int i){ if(i >= sz(t) || i < 0) return 0; return szz[i]; }

    void add_string(string const& s)
    {
        int v = 0;
        szz[v]++;

        trav(ch, s)
        {
            int c = ch - 'a';

            if(t[v].next[c] == -1)
            {
                t[v].next[c] = sz(t);
                t.emplace_back();
                szz.emplace_back();
            }

            v = t[v].next[c];
            szz[v]++;
        }

        t[v].leaf = 1;
    }

    void add_binary_string(int n)
    {
        int v = 0;
        szz[v]++;

        frev(j, 0, 30)
        {
            int c = n >> j & 1;

            if(t[v].next[c] == -1)
            {
                t[v].next[c] = sz(t);
                t.emplace_back();
                szz.emplace_back();
            }

            v = t[v].next[c];
            szz[v]++;
        }

        t[v].leaf = 1;
    }
};