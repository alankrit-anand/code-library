template<class T>
struct rmq_2D
{
    int n, m;
    vector<vector<vector<vector<T>>>> a;

    T combine(T x, T y){
        return min(x, y);
    }

    rmq_2D(vector<vector<T>> b)
    {
        int n = sz(b), m = sz(b[0]);
        a.resize(10, vector<vector<vector<T>>>(10, vector<vector<T>>(n, vector<T>(m))));

        a[0][0] = b;

        rep(i,0,10)
        {
            rep(j,0,10)
            {
                for(int r = 0; r + (1 << i) <= n; r++)
                {
                    for(int c = 0; c + (1 << j) <= m; c++)
                    {
                        if(i == 0)
                        {
                            if(j)
                            {
                                a[i][j][r][c] = combine(a[i][j-1][r][c], a[i][j-1][r][c + (1 << (j - 1))]);
                            }
                        }
                        else
                        {
                            a[i][j][r][c] = combine(a[i-1][j][r][c], a[i-1][j][r + (1 << (i - 1))][c]);

                            if(j)
                            {
                                a[i][j][r][c] = combine(a[i][j][r][c], a[i][j-1][r][c]);
                                a[i][j][r][c] = combine(a[i][j][r][c], a[i][j-1][r][c + (1 << (j - 1))]);
                            }
                        }
                    }
                }
            }
        }
    }


    T qry(int r1, int c1, int r2, int c2)
    {
        int z1 = 63 - __builtin_clzll(r2 - r1 + 1);
        int z2 = 63 - __builtin_clzll(c2 - c1 + 1);

        T res = combine(a[z1][z2][r1][c1], a[z1][z2][r2 - (1 << z1) + 1][c2 - (1 << z2) + 1]);
        res = combine(res, a[z1][z2][r1][c2 - (1 << z2) + 1]);
        res = combine(res, a[z1][z2][r2 - (1 << z1) + 1][c1]);

        return res;
    }

};