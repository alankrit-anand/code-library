struct pt{

    int x, y;

    pt() : x(0), y(0) {}
    pt(int _x, int _y) : x(_x), y(_y) {} 

    bool operator <(const pt& p) const { if(x != p.x) return x < p.x; return y < p.y;}
    bool operator ==(const pt& p) const { return x == p.x && y == p.y; }

    pt operator +(const pt& p) const { return pt(x + p.x, y + p.y); }
    pt operator -(const pt& p) const { return pt(x - p.x, y - p.y); }
    pt operator *(const int& z) const { return pt(x * z, y * z); }
    pt operator /(const int& z) const { return pt(x / z, y / z); }

    void operator +=(const pt& p) { (*this) = (*this) + p; }
    void operator -=(const pt& p) { (*this) = (*this) - p; }

    int dot(pt p) { return x * p.x + y * p.y; }
    int cross(pt p){ return x * p.y - y * p.x; }
    int cross(pt a, pt b) const { return (a - *this).cross(b - *this); }
    ld dis() { return sqrt(x * x + y * y); }
    ld dis(pt p){ return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); }

    bool lies_on_segment(pt p1, pt p2){ if(cross(p1, p2)) return 0; return min(p1.x, p2.x) <= x && x <= max(p1.x, p2.x) && min(p1.y, p2.y) <= y && y <= max(p1.y, p2.y); }
    bool cw(pt b, pt c) { return x * (b.y - c.y) + b.x * (c.y - y)+ c.x * (y - b.y) < 0; }
    bool ccw(pt b, pt c) { return x * (b.y - c.y) + b.x * (c.y - y)+ c.x * (y - b.y) > 0; }

};


bool line_intersection(pt p1, pt p2, pt p3, pt p4){
    if((p2 - p1).cross(p4 - p3) == 0){
        if(p1.cross(p2, p3)) 
            return 0;
        rep(_, 0, 2){
            if(max(p1.x, p2.x) < min(p3.x, p4.x) && max(p1.y, p2.y) < min(p3.y, p4.y)) 
                return 0;
            swap(p1, p3), swap(p2, p4);
        }
        return 1;
    }

    rep(_, 0, 2){
        int x = p1.cross(p2, p3), y = p1.cross(p2, p4);
        int sgn1 = x > 0 ? 1 : (x == 0 ? 0 : -1);
        int sgn2 = y > 0 ? 1 : (y == 0 ? 0 : -1);
        if(sgn1 * sgn2 > 0)
            return 0;
        swap(p1, p3), swap(p2, p4);
    }
    return 1;
}


void convex_hull(vector<pt>& a) {

    if (sz(a) == 1)
        return;

    sort(all(a));
    pt p1 = a[0], p2 = a.back();
    vector<pt> up = {p1}, down = {p1};

    rep(i,1,sz(a)){
        if (i == sz(a) - 1 || p1.cross(a[i], p2) <= 0) {
            while (sz(up) >= 2 && up[sz(up)-2].cross(up.back(), a[i]) > 0)
                up.pop_back();
            up.pb(a[i]);
        }
        if (i == sz(a) - 1 || p1.cross(a[i], p2) >= 0) {
            while(sz(down) >= 2 && down[down.size()-2].cross(down.back(), a[i]) < 0)
                down.pop_back();
            down.pb(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < sz(up); i++)
        a.pb(up[i]);
    for (int i = sz(down) - 2; i > 0; i--)
        a.pb(down[i]);
}
