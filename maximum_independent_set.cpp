// g in form of bitmask
// ensure g[i][i] = 1

int max_independent_set(vi &g, int n)
{
    int h = n / 2;
    vi sos(1 << h);

    rep(msk, 0, 1 << h)
    {
        int msk1 = 0;
        bool ok = 1;

        rep(j,0,h)
        {
            if(msk >> j & 1)
            {
                if(msk1 >> j & 1)
                {
                    ok = 0;
                    break;
                }

                msk1 |= g[j];
            }
        }

        if(ok)
        {
            sos[msk] = __builtin_popcountll(msk);
        }
    }


    rep(j,0,h)
    {
        rep(msk, 0, 1 << h)
        {
            if(msk >> j & 1)
            {
                maxi(sos[msk], sos[msk ^ (1 << j)]);
            }
        }
    }


    int res = 0, full_msk = (1 << h) - 1;

    rep(msk, 0, 1 << (n - h))
    {
        int msk1 = 0;
        bool ok = 1;

        rep(j,0,n-h)
        {
            if(msk >> j & 1)
            {
                if(msk1 >> (h + j) & 1)
                {
                    ok = 0;
                    break;
                }

                msk1 |= g[h + j];
            }
        }

        if(ok)
        {
            int nmsk = full_msk ^ (full_msk & msk1);
            maxi(res, sos[nmsk] + __builtin_popcount(msk));
        }
    }

    return res;
}
