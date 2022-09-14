struct S{

    int x, y;

    bool operator <(const S other) const {
        x * other.y < y * other.x;
    }

};