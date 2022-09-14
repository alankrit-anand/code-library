struct Matrix : vvi {

    int n, m;

    Matrix() : vvi() {}
    Matrix(int _n) : vvi(_n, vi(_n)), n(_n), m(_n) {}
    Matrix(int _n, int _m) : vvi(_n, vi(_m)), n(_n), m(_m) {}

    void identity_matrix(){
        assert(n == m);
        rep(i,0,n){
            rep(j,0,n){
                (*this)[i][j] = i == j;
            }
        }
    }

    Matrix operator *(Matrix other) {
        assert(m == other.n);
        Matrix temp(n, other.m);
        rep(i, 0, n)
            rep(j, 0, other.m)
                rep(k, 0, m)
                    (temp[i][j] += (*this)[i][k] * other[k][j]) %= mod;
        return temp;
    }

    Matrix powm(int pow){
        assert(n == m);
        Matrix temp = *this;
        Matrix ret(n);
        ret.identity_matrix();

        while(pow){
            if (pow & 1){
                ret = ret * temp;
            }
            temp = temp * temp;
            pow /= 2;
        }

        return ret;
    }

};