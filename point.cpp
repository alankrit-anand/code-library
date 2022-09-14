const ld pi = acos(-1);
const ld eps = 1e-9;

struct pt{

    ld x, y;

    pt() : x(0), y(0) {}
    pt(ld _x, ld _y) : x(_x), y(_y) {} 

    bool operator <(const pt& p) const { if(abs(x - p.x) < eps) return x < p.x; return y < p.y - eps;}
    bool operator ==(const pt& p) const { return abs(x - p.x) < eps && abs(y - p.y) < eps; }

    pt operator +(const pt& p) const { return pt(x + p.x, y + p.y); }
    pt operator -(const pt& p) const { return pt(x - p.x, y - p.y); }
    pt operator *(const ld& z) const { return pt(x * z, y * z); }
    pt operator /(const ld& z) const { return pt(x / z, y / z); }

    void operator +=(const pt& p) { (*this) = (*this) + p; }
    void operator -=(const pt& p) { (*this) = (*this) - p; }

    ld dot(pt p) { return x * p.x + y * p.y; }
    ld cross(pt p){ return x * p.y - y * p.x; }
    ld cross(pt a, pt b) const { return (a - *this).cross(b - *this); }
    ld dis() { return sqrt(x * x + y * y); }
    ld dis(pt p){ return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); }

    pt unit() { return (*this) / dis(); }
    pt normal() { return pt(-y, x); }
    pt rotate(ld a) { return pt(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)); }
    
    bool lies_on_segment(pt p1, pt p2){ return abs(dis(p1) + dis(p2) - p1.dis(p2)) < eps; }
    bool lies_on_ray(pt p1, pt p2){
        if(cross(p1, p2) > eps) return 0;
        return abs(abs(dis(p1) - p1.dis(p2)) - dis(p2)) < eps;
    }

    friend istream& operator >>(istream& is, pt& p) { return is >> p.x >> p.y; }
    friend ostream& operator <<(ostream& os, pt& p){ return os << p.x << ' ' << p.y; }

};

pair<int, pt> line_intersection(pt s1, pt e1, pt s2, pt e2) {
    // 1 -> unique solution    0 -> no solution    -1 -> infinite solution 
    ld d = (e1 - s1).cross(e2 - s2);
    if(abs(d) < eps)
        return {-(abs(s1.cross(e1, s2)) < eps), pt(0, 0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}

struct line {

    ld a, b, c;

    line() {}
    line(pt p, pt q){
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm(){
        ld z = sqrt(a * a + b * b);
        if(abs(z) > eps)
            a /= z, b /= z, c /= z;
    }

    ld dis(pt p){ 
        return a * p.x + b * p.y + c; 
    }

    pair<pt, pt> end_points(){
        if(abs(b) < eps){
            return { pt(-c / a, 0), pt(-c / a, 1) };
        }
        return { pt(0, -c / b) , pt(1, -(c + a) / b) };
    }

    friend istream& operator >>(istream& is, line& l) { return is >> l.a >> l.b >> l.c; }
    friend ostream& operator <<(ostream& os, line& l){ return os << l.a << ' ' << l.b << ' ' << l.c; }
};
