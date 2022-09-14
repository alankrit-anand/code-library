void radix_sort(vector<pair<pii, int>> &a){

    int n = sz(a);

    {

        vi cnt(n), pos(n);
        vector<pair<pii, int>> new_a(n);
        rep(i,0,n){
            cnt[a[i].fi.se]++;
        }
        rep(i,1,n)
            pos[i] = pos[i-1] + cnt[i-1];
        rep(i,0,n){
            new_a[pos[a[i].fi.se]++] = a[i];
        }

        a = new_a;
    }

    {

        
        vi cnt(n), pos(n);
        vector<pair<pii, int>> new_a(n);
        rep(i,0,n){
            cnt[a[i].fi.fi]++;
        }
        rep(i,1,n)
            pos[i] = pos[i-1] + cnt[i-1];
        rep(i,0,n){
            new_a[pos[a[i].fi.fi]++] = a[i];
        }

        a = new_a;
    }



}


struct suffix_array{

    string s;
    int n;
    vi p, c, lcp;
    vi rmq[20];


    void solve(){

        vpii a(n);
        rep(i,0,n){
            a[i] = {s[i], i};
        }
        sort(all(a));

        rep(i,0,n){
            p[i] = a[i].se;
        }

        c[p[0]] = 0;
        rep(i,1,n){
            c[p[i]] = c[p[i-1]] + (a[i].fi != a[i-1].fi);
        }


        int k = 0;

        while((1 << k) < n){

            vector<pair<pii, int>> a(n);
            rep(i,0,n){
                a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
            }

            radix_sort(a);

            rep(i,0,n){
                p[i] = a[i].se;
            }

            c[p[0]] = 0;
            rep(i,1,n){
                c[p[i]] = c[p[i-1]] + (a[i].fi != a[i-1].fi);
            }

            k++;
        }


    }


    suffix_array(string _s){
        s = _s;
        n = sz(s);
        p.resize(n);
        c.resize(n);
        solve();
    }


    void build_rmq(){

        rmq[0].resize(n-1);
        rep(i,0,n-1)
            rmq[0][i] = lcp[i+1];

        rep(k,1,20){
            rmq[k].resize(n-1);
            rep(i, 0, n - (1 << k)){
                int j = i + (1 << (k - 1));
                rmq[k][i] = min(rmq[k-1][i], rmq[k-1][j]);
            }
        }

    }


    void build_lcp(){
        lcp.resize(n);
        int k = 0;
        rep(i,0,n-1){
            int pos = c[i];
            int j = p[pos-1];
            while(s[i+k] == s[j+k])
                k++;
            lcp[pos] = k;
            if(k)
                k--;
        }
    }

    int longest_common_prefix(int i, int j){
        if(i == j)
            return n - i;
        int pos1 = c[i], pos2 = c[j];
        if(pos1 > pos2)
            swap(pos1, pos2);

        int x = 63 - __builtin_clzll(pos2 - pos1);
        return min(rmq[x][pos1], rmq[x][pos2 - (1 << x)]);
    }

};

// Append '#' before building suffix_array