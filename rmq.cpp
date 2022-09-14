template<class T>
struct rmq{

    int n;
    vector<vector<T>> a;

    T combine(T x, T y)
    {
        return min(x, y);
    }

    rmq(vector<T> b)
    {
        int n = sz(b);
        a.resize(20, vector<T>(n));
        a[0] = b;

        rep(j, 1, 20)
        {
            for(int i = 0; i + (1 << j) <= n; i++)
            {
                a[j][i] = combine(a[j - 1][i], a[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T qry(int l, int r)
    {
        int z = 63 - __builtin_clzll(r - l + 1);
        return combine(a[z][l], a[z][r - (1 << z) + 1]);
    }
};