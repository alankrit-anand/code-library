struct Basis
{
    int d, sz;
    vi basis;

    Basis(int d) : d(d)
    {
        basis.resize(d);
        sz = 0;
    }

    bool insertVector(int mask) 
    {
        for (int i = 0; i < d; i++) 
        {
            if ((mask & 1 << i) == 0) 
                continue; 

            if (!basis[i]) 
            { 
                basis[i] = mask;
                ++sz;
                return 1;
            }

            mask ^= basis[i];
        }

        return 0;
    }
};