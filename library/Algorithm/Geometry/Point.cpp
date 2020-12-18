/* 幾何ライブラリ */
const double DINF = 1LL<<60;      // to be set appropriately
const double EPS = 1e-10;        // to be set appropriately
const double PI = acosl(-1.0);
double torad(int deg) {return (double)(deg) * PI / 180;}
double todeg(double ang) {return ang * 180 / PI;}

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    friend ostream& operator << (ostream &s, const Point &p) {return s << '(' << p.x << ", " << p.y << ')';}
};
inline Point operator + (const Point &p, const Point &q) {return Point(p.x + q.x, p.y + q.y);}
inline Point operator - (const Point &p, const Point &q) {return Point(p.x - q.x, p.y - q.y);}
inline Point operator * (const Point &p, double a) {return Point(p.x * a, p.y * a);}
inline Point operator * (double a, const Point &p) {return Point(a * p.x, a * p.y);}
inline Point operator * (const Point &p, const Point &q) {return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}
inline Point operator / (const Point &p, double a) {return Point(p.x / a, p.y / a);}
inline Point conj(const Point &p) {return Point(p.x, -p.y);}
inline Point rot(const Point &p, double ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);}
inline Point rot90(const Point &p) {return Point(-p.y, p.x);}
inline double cross(const Point &p, const Point &q) {return p.x * q.y - p.y * q.x;}
inline double dot(const Point &p, const Point &q) {return p.x * q.x + p.y * q.y;}
inline double norm(const Point &p) {return dot(p, p);}
inline double abs(const Point &p) {return sqrt(dot(p, p));}
inline double amp(const Point &p) {double res = atan2(p.y, p.x); if (res < 0) res += PI*2; return res;}
inline bool eq(const Point &p, const Point &q) {return abs(p - q) < EPS;}
inline bool operator < (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);}
inline bool operator > (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);}
inline Point operator / (const Point &p, const Point &q) {return p * conj(q) / norm(q);}

struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream& operator << (ostream &s, const Line &l) {return s << '{' << l[0] << ", " << l[1] << '}';}
};

// 1：a-bから見てcは左側(反時計回り)、-1：a-bから見てcは右側(時計回り)、0：一直線上
int simple_ccw(const Point &a, const Point &b, const Point &c) {
    if (cross(b-a, c-a) > EPS) return 1;
    if (cross(b-a, c-a) < -EPS) return -1;
    return 0;
}

// 円や直線の交点
vector<Point> crosspoint(const Line &l, const Line &m) {
    vector<Point> res;
    double d = cross(m[1] - m[0], l[1] - l[0]);
    if (abs(d) < EPS) return vector<Point>();
    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);
    return res;
}

// 外心
Point gaisin(Point a, Point b, Point c) {
    Line ab((a+b)/2, (a+b)/2 + rot90(a-b));
    Line bc((b+c)/2, (b+c)/2 + rot90(b-c));
    return crosspoint(ab, bc)[0];
}