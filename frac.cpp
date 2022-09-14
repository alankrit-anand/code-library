struct frac 
{
    int p, q;

    void simplify() 
    {
        if(q < 0) {
            p *= -1;
            q *= -1;
        }

        int g = __gcd(p < 0 ? -p : p, q);

        if(g) {
            p /= g;
            q /= g;
        }
    }

    frac(int p = 0, int q = 1) : p(p), q(q) { simplify(); }

    bool operator <(const frac &other) const { return (__int128) p * other.q < (__int128) q * other.p; }
    bool operator >(const frac &other) const { return (__int128) p * other.q > (__int128) q * other.p; }
    bool operator ==(const frac &other) const { return (__int128) p * other.q == (__int128) q * other.p; }
    bool operator <=(const frac &other) const { return *this < other || *this == other; }
    bool operator >=(const frac &other) const { return *this > other || *this == other; }

    template <class T> bool operator <(const T &other) const { return *this < frac(other); }
    template <class T> bool operator >(const T &other) const { return *this > frac(other); }
    template <class T> bool operator ==(const T &other) const { return *this == frac(other); }
    template <class T> bool operator >=(const T &other) const { return *this >= frac(other); }
    template <class T> bool operator <=(const T &other) const { return *this <= frac(other); }
 
    frac &operator +=(const frac &r) {
        int g = __gcd(q, r.q);
        p = r.q / g * p + q / g * r.p;
        q = q / g * r.q;
        (*this).simplify();
        return *this;
    }
     
    frac &operator -=(const frac &r) {
        int g = __gcd(q, r.q);
        p = r.q / g * p - q / g * r.p;
        q = q / g * r.q;
        (*this).simplify();
        return *this;
    }

    frac &operator *=(const frac &r) {
        p *= r.p;
        q *= r.q;
        (*this).simplify();
        return *this;
    }

    frac &operator /=(const frac &r) {
        p *= r.q;
        q *= r.p;
        (*this).simplify();
        return *this;
    }

    frac operator +(const frac r) const { return frac(p, q) += r; }
    frac operator -(const frac r) const { return frac(p, q) -= r; }
    frac operator *(const frac r) const { return frac(p, q) *= r; }
    frac operator /(const frac r) const { return frac(p, q) /= r; }
};