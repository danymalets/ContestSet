#pragma region TEMPLATE

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define fast_io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define erun(x) (x).erase(unique(all(x)),(x).end())
#define sp(x) setprecision(x) << fixed
#define setp(x) cout << setprecision(x) << fixed
#define all(x) (x).begin(),(x).end()
#define dcl(x,y) ((x)%(y)?(x)/(y)+1:(x)/(y))
#define cube(x) ((x)*(x)*(x))
#define sqr(x) ((x)*(x))
#define bg1 cout << '!'
#define bg2 cout << '?'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define file_all file_in,file_out
#define file_in freopen("input.txt","rt",stdin)
#define file_out freopen("output.txt","wt",stdout)
#define print_time() cerr << sp(2) << "\nTime execute: " << clock() / (double)CLOCKS_PER_SEC << " sec\n";

int gcd(int x, int y){ return __gcd(x, y); }
int gcd(ll x, ll y){ return __gcd(x, y); }
ll lcm(int x, int y){ return 1LL * x * y / gcd(x, y); }

ld root(ld n, ld x){ return pow(x, 1 / n); }
ld log(ld n, ld x){ return log(x) / log(n); }
int pow2(int n){ return (1 << n); }
ll pow2ll(int n){ return (1LL << n); }
bool is_pow2(int x){ return !(x&(x-1)); }
bool is_pow2(ll x){ return !(x&(x-1)); }
bool is_sqr(int x){ int t = sqrt(x); return t * t == x; }
bool is_sqr(ll x){ int t = sqrt(x); return 1LL * t * t == x; }

int bin_pow(int x, int n, int mod){
    if (n == 0) return 1 % mod;
    if (n % 2 == 1) return 1LL * bin_pow(x, n - 1, mod) * x % mod;
    int t = bin_pow(x, n / 2, mod);
    return t * t % mod;
}

int bin_pow(int x, ll n, int mod){
    if (n == 0) return 1 % mod;
    if (n % 2 == 1) return 1LL * bin_pow(x, n - 1, mod) * x % mod;
    int t = bin_pow(x, n / 2, mod);
    return t * t % mod;
}

void print() { }
template<typename First, typename... Strings> void print(First arg, const Strings&... rest) { cout << arg << " "; print(rest...); }
void println() { cout << '\n'; }
template<typename First, typename... Strings> void println(First arg, const Strings&... rest) { cout << arg << " "; println(rest...); }
template<typename T> void printv(vector<T> v) { for (int i = 0; i < v.size(); i++) print(v[i]); }
template<typename T> void printvln(vector<T> v) { printv(v); println(); }
template<typename T> void printa(T a[], int l, int r) { for (int i = l; i < r; i++) print(a[i]); }
template<typename T> void printaln(T a[], int l, int r) { printa(a, l, r); println(); }
template<typename T> void printa(T a[], int n) { printa(a, 0, n); }
template<typename T> void printaln(T a[], int n) { printaln(a, 0, n); }

#pragma endregion TEMPLATE

const ll LLINF = 8e18;
const int INF = 2e9;

const int MOD = 1e9+7;
const int M = 1000;
const int N = 2e5;

const ld EPS = 1e-10;

struct scalar{
    ld v;

    scalar() {}
    scalar(ld v) : v(v){}

    friend istream& operator>>(istream &stream, scalar &s) { return stream >> s.v; }
    friend ostream& operator<<(ostream &stream, const scalar &s) { return stream << s.v; }

    scalar operator+(const scalar &s) const { return v + s.v; }
    scalar operator-(const scalar &s) const { return v - s.v; }
    scalar operator*(const scalar &s) const { return v * s.v; }
    scalar operator/(const scalar &s) const { return v / s.v; }
    scalar operator%(const scalar &s) const { return fmodl((*this).v, s.v); }
    scalar operator-() const { return -(*this).v; }

    void operator+=(const scalar &s) { *this = *this + s; }
    void operator-=(const scalar &s) { *this = *this - s; }
    void operator*=(const scalar &s) { *this = *this * s; }
    void operator/=(const scalar &s) { *this = *this / s; }

    bool operator==(const scalar &s) const { return abs(v - s.v) < EPS; }
    bool operator!=(const scalar &s) const { return abs(v - s.v) >= EPS; }
    bool operator<(const scalar &s) const { return v + EPS < s.v; }
    bool operator>(const scalar &s) const { return v > s.v + EPS; }
    bool operator<=(const scalar &s) const { return !((*this) > s); }
    bool operator>=(const scalar &s) const { return !((*this) < s); }

    bool is_between_inclusive(scalar a, scalar b){
        scalar mn = min(a.v, b.v);
        scalar mx = max(a.v, b.v);
        return *this >= mn && *this <= mx;
    }

    friend scalar simplify_angle(scalar a){ return mod_scalar(a, PI() * 2); }
    friend scalar minimize_angle(scalar a){ scalar t = simplify_angle(a); return min(t, PI() * 2 - t); }
    friend scalar angle(scalar a, scalar b) { return simplify_angle(b-a); }

    friend scalar min_angle(scalar a, scalar b) { return minimize_angle(b-a); }
//    scalar& operator=(const ld& x) {return *this; }

    static scalar PI() { return 3.14159265358979323846264338327950288L; }
    static scalar E()  { return 2.71828182845904523536028747135266250L; }

    friend scalar sqrt(scalar t){ return sqrtl(t.v); }
    friend scalar abs(scalar t){ return abs(t.v); }

    friend scalar cos(scalar t){ return cosl(t.v); }
    friend scalar sin(scalar t){ return sinl(t.v); }
    friend scalar tan(scalar t){ return tanl(t.v); }
    friend scalar cot(scalar t){ return 1 / tanl(t.v); }

    friend scalar acos(scalar t){ return acosl(t.v); }
    friend scalar asin(scalar t){ return asinl(t.v); }
    friend scalar atan(scalar t){ return atanl(t.v); }
    friend scalar acot(scalar t){ return PI()*2-atanl(t.v); }

    friend scalar log(scalar n, scalar a){ return logl(a.v) / logl(n.v); }
    friend scalar pow(scalar a, scalar n){ return powl(a.v, n.v); }
    friend scalar root(scalar n, scalar a){ return powl(a.v, 1/n.v); }

    friend scalar mod_value(scalar a, scalar m){ return (a % m + m) % m; }
    friend scalar mod_scalar(scalar a, scalar m){
        scalar ans = mod_value(a,m);
        if (ans == m) ans = 0;
        return ans;
    }

    friend scalar triangle_area(scalar a, scalar b, scalar c){
        scalar p = (a + b + c) / 2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    friend scalar triangle_height(scalar a, scalar b, scalar c){ return triangle_area(a, b, c) * 2 / a; } // ha
    friend scalar triangle_angle(scalar a, scalar b, scalar c){
        return acos((sqr(b) * sqr(c) - sqr(a)) / (b * c * 2));
    } // between b and c

    scalar rad2deg(scalar a){ return a * 180 / scalar::PI(); }
    scalar deg2rad(scalar a){ return a * scalar::PI() / 180; }
};

struct vector2{
    scalar x, y;

    vector2() {}
    vector2(scalar x, scalar y) : x(x), y(y) {}

    friend istream& operator>>(istream &stream, vector2 &v) { return stream >> v.x >> v.y; }
    friend ostream& operator<<(ostream &stream, const vector2 &v) { return stream << "(" << v.x << ", " << v.y << ")"; }

    vector2 move(vector2 direction, scalar len){ return *this + direction.new_with_length(len); }

    vector2 rotate(scalar a){ return by_angle_and_distance(angle() + a, magnitude()); }
    vector2 rotate_around(vector2 center, scalar a){ return center + (*this - center).rotate(a); }
    scalar angle(){ return (*this) == zero() ? 0 : atan2l(y.v, x.v); } // [-p, +p]
    scalar angle_to(vector2 o){ return (o - (*this)).angle(); } // [-p, +p]

    vector2 reversed() const { return vector2(-x, -y); }

    scalar sqr_magnitude(){ return x * x + y * y; }
    scalar magnitude(){ return sqrt(sqr_magnitude()); }
    vector2 normalized(){ return new_with_length(1); }
    vector2 new_with_length(scalar new_len){
        scalar len = magnitude();
        return vector2(x * new_len / len, y * new_len / len);
    }

    vector2 left_perpendicular() { return vector2(-y, x); }
    vector2 right_perpendicular() { return vector2(y, -x); }

    bool operator==(const vector2 &v) const { return x == v.x && y == v.y; }
    bool operator!=(const vector2 &v) const { return !(*this == v); }
    bool operator<(const vector2 &v) const { return x.v == v.x.v ? y.v < v.y.v : x.v < v.x.v; }

    vector2 operator+(const vector2 &v) const { return vector2(x + v.x, y + v.y); }
    vector2 operator-(const vector2 &v) const { return vector2(x - v.x, y - v.y); }
    vector2 operator*(const vector2 &v) const { return vector2(x * v.x, y * v.y); }
    vector2 operator*(const scalar &t) const { return vector2(x * t, y * t); }
    vector2 operator/(const vector2 &v) const { return vector2(x / v.x, y / v.y); }
    vector2 operator/(const scalar &t) const { return vector2(x / t, y / t); }
    vector2 operator-() const { return reversed(); }

    static vector2 by_angle_and_distance(scalar a, scalar d){
        return vector2((scalar)cosl(a.v) * d, (scalar)sinl(a.v) * d);
    }

    static bool is_parallel(vector2 a, vector2 b) { return a.x * b.y == a.y * b.x; }

    static bool is_same_direction(vector2 a, vector2 b) { return is_parallel(a, b) && a.x * b.x + a.y * b.y > 0; }
    static bool is_opposite_direction(vector2 a, vector2 b) { return is_parallel(a, b) && a.x * b.x + a.y * b.y < 0; }

    static bool is_opposite(vector2 a, vector2 b) { return a == -b; }
    static bool is_perpendicular(vector2 a, vector2 b) { return -a.x * b.y == a.y * b.x; }

    static scalar distance(vector2 x, vector2 y) { return (x - y).magnitude(); }
    static scalar angle(vector2 a, vector2 b) {
        return simplify_angle(b.angle() - a.angle());
    } // [0, 2*pi] positive circle

    static scalar angle(vector2 a, vector2 b, vector2 c){ // positive circle
        return simplify_angle(b.angle_to(a) - b.angle_to(c));
    }

    static vector2 O() { return vector2(0, 0); }
    static vector2 zero() { return vector2(0, 0); }
    static vector2 right() { return vector2(1, 0); }
    static vector2 up() { return vector2(0, 1); }
    static vector2 left() { return vector2(-1, 0); }
    static vector2 down() { return vector2(0, -1); }
    static vector2 one() { return vector2(1, 1); }
};

struct segment{
    vector2 p1, p2;

    segment() {}
    segment(vector2 p1, vector2 p2) : p1(p1), p2(p2) {}
    segment(scalar x1, scalar y1, scalar x2, scalar y2) : p1(x1, y1), p2(x2, y2) {}

    friend istream& operator>>(istream &stream, segment &v) { return stream >> v.p1 >> v.p2; }
    friend ostream& operator<<(ostream &stream, const segment &s) {
        return stream << "(" << s.p1 << ", " << s.p2 << ")";
    }

    segment rotate_around(vector2 center, scalar a){
        return segment(p1.rotate_around(center, a), p2.rotate_around(center, a));
    }

    bool contains(vector2 o) {
        return (p2.y - p1.y) * (o.x - p1.x) == (p2.x - p1.x) * (o.y - p1.y) && is_line_point_on_segment(o);
    }
    bool is_line_point_on_segment(vector2 p){
        return p.x.is_between_inclusive(p1.x, p2.x) && p.y.is_between_inclusive(p1.y, p2.y);
    }


    scalar length(){ return (p2 - p1).magnitude(); }
    scalar sqr_length(){ return (p2 - p1).sqr_magnitude(); }

    vector2 part(scalar p){ return p1 + (p2 - p1) * p; }
    vector2 center(){ return (p1 + p2) / 2; }
    vector2 ratio(scalar a, scalar b){ return p1 + (p2 - p1) * a / (a + b); }

    segment reversed() const { return segment(p2, p1); }
    segment operator-() const { return reversed(); }

    static bool are_same_or_opposite(segment a, segment b) { return a == b || a == -b; };
    bool operator==(const segment &s) const { return p1 == s.p1 && p2 == s.p2; }
    bool operator!=(const segment &s) const { return !((*this) == s); }
};

struct line{
    vector2 p, d;

    line() {}
    line(vector2 p, vector2 d) : p(p), d(d) {}
    line(segment s) : line(s.p1, s.p2 - s.p1) {}

    scalar A() { return -d.y; }                    // Ax + By + C = 0
    scalar B() { return d.x; }
    scalar C() { return d.y*p.x-d.x*p.y; }

    scalar k() { return d.y / d.x; }               // y = kx + b
    scalar b() { return p.y - d.y * p.x / d.x; }

    friend istream& operator>>(istream &stream, line &v) { return stream >> v.p >> v.d; }
    friend ostream& operator<<(ostream &stream, const line &v) {
        return stream << "{ line : p = " << v.p << ", d = " << v.d << " }";
    }

    line rotate_around(vector2 center, scalar a){ return line(p.rotate_around(center, a), d.rotate(a)); }

    bool contains(vector2 o) const { return d.y * (o.x - p.x) == d.x * (o.y - p.y); }
    bool is_point_left(vector2 o){ return d.y * (o.x - p.x) - d.x * (o.y - p.y) < 0; }
    bool is_point_right(vector2 o){ return d.y * (o.x - p.x) - d.x * (o.y - p.y) > 0; }

    vector2 any_point(int i = 0) const { return p + d * i; }
    segment any_segment(int i = 0) const { return segment(any_point(i), any_point(i + 1)); }

    line move_right(scalar dist) {
        return perpendicular_with(p.move(d.right_perpendicular(), dist));
    }
    line move_left(scalar dist) { return move_right(-dist); }

    line perpendicular() { return left_perpendicular(); }
    line left_perpendicular() { return line(p, d.left_perpendicular()); }
    line right_perpendicular() { return line(p, d.right_perpendicular()); }

    scalar distance_to(segment s){
        if (is_intersect(s)) return 0;
        return min(distance_to(s.p1), distance_to(s.p2));
    }

    line normalized() { return line(p, d.normalized()); }

    line reversed() const { return line(p, -d); }

    bool is_intersect(segment s){
        line ln = line(s);
        if (!is_intersect(*this, ln)) return false;
        vector2 o = intersection_point(*this, ln);
        return s.is_line_point_on_segment(o);
    }

    vector2 intersection_point(segment s){
        assert(is_intersect(*this, s));
        return intersection_point(*this, line(s));
    }

    line left_perpendicular_with(vector2 o){ return line(o, d.left_perpendicular()); }
    line right_perpendicular_with(vector2 o){ return line(o, d.right_perpendicular()); }
    line perpendicular_with(vector2 o){ return left_perpendicular_with(o); }

    line parallel_with(vector2 o){ return line(o, d); }

    vector2 nearest_point(vector2 o){
        line n = perpendicular_with(o);
        return line::intersection_point(*this, n);
    }

    scalar distance_to(vector2 o){
        return vector2::distance(o, nearest_point(o));
    }

    line operator-() const { return reversed(); }

    static bool is_intersect(segment a, segment b) {
        if (is_same_or_opposite(line(a), line(b))){
            return a.is_line_point_on_segment(b.p1) ||
                   a.is_line_point_on_segment(b.p2) ||
                   b.is_line_point_on_segment(a.p1) ||
                   b.is_line_point_on_segment(a.p2);
        }
        return is_intersect_in_point(a,b);
    }

    static bool is_intersect_in_point(segment a, segment b) {
        if (!is_intersect(line(a), line(b))) return false;
        vector2 p = intersection_point(line(a), line(b));
        return a.is_line_point_on_segment(p) && b.is_line_point_on_segment(p);
    }

    static vector2 intersection_point(segment a, segment b) {
        return intersection_point(line(a), line(b));
    }

    static scalar distance(line a, line b){
        if (is_intersect(a, b)) return 0;
        return a.distance_to(b.any_point());
    }

    static scalar distance(segment s, vector2 p){
        line a = line(s);
        line b = a.perpendicular_with(p);
        if (b.is_intersect(s)) return vector2::distance(b.intersection_point(s), p);
        else return min(vector2::distance(s.p1, p), vector2::distance(s.p2, p));
    }

    static scalar distance(segment a, segment b){
        if (is_intersect(a, b)) return 0;
        else return min(min(distance(a, b.p1), distance(a, b.p2)),
                        min(distance(b, a.p1), distance(b, a.p2)));
    }

    static bool is_parallel(line a, line b) { return vector2::is_parallel(a.d, b.d); } // equals lines are parallel
    static bool is_intersect(line a, line b) { return !is_parallel(a, b); } // 1 point not equals
    static bool is_perpendicular(line a, line b) { return vector2::is_perpendicular(a.d, b.d); }

    static vector2 intersection_point(line a, line b){
        assert(is_intersect(a, b));
        scalar val1 = (a.p.x + a.d.x) * a.p.y - (a.p.y + a.d.y) * a.p.x;
        scalar val2 = (b.p.x + b.d.x) * b.p.y - (b.p.y + b.d.y) * b.p.x;
        scalar val3 = (a.d.x * b.d.y - a.d.y * b.d.x);
        scalar x = (val1 * b.d.x - val2 * a.d.x) / val3;
        scalar y = (val1 * b.d.y - val2 * a.d.y) / val3;
        return vector2(x, y);
    }

    static bool is_same_direction(line a, line b){ return vector2::is_same_direction(a.d, b.d); }

    static bool is_same_or_opposite(line a, line b) { return is_parallel(a, b) && a.contains(b.p); };
    bool operator==(const line &line) const { return is_same_direction(*this, line) && contains(line.p); }

    static line Ox() { return line(vector2::O(), vector2::right()); }
    static line Oy() { return line(vector2::O(), vector2::up()); }

    static line by_point_and_angle(vector2 p, scalar a){ return line(p, vector2::by_angle_and_distance(a, 1)); }

    static line from_ABC(scalar A, scalar B, scalar C){
        return line(A == 0 ? vector2( 0, -C/B) : vector2(-C/A, 0), vector2(B, -A));
    }
    static line from_kb(scalar k, scalar b){ return line(vector2(0, b), vector2(1, k)); }

    static line left_perpendicular_bisector(segment s){
        return line(s).left_perpendicular_with(s.center());
    }
    static line right_perpendicular_bisector(segment s){
        return line(s).right_perpendicular_with(s.center());
    }
    static line perpendicular_bisector(segment s){
        return left_perpendicular_bisector(s);
    }
};

struct circle{
    vector2 c;
    scalar r;

    circle() {}
    circle(vector2 c, scalar r): c(c), r(r) {}
    circle(scalar x, scalar y, scalar r): c(x, y), r(r) {}

    friend istream& operator>>(istream &stream, circle &cir) { return stream >> cir.c >> cir.r; }
    friend ostream& operator<<(ostream &stream, const circle &cir) {
        return stream << "{ circle : c = " << cir.c << ", r = " << cir.r << " }";
    }

    scalar distance_to(vector2 p){ return min(scalar(0), vector2::distance(c, p) - r); }
    scalar distance_to(line ln){ return min(scalar(0), ln.distance_to(c) - r); }

    bool is_intersect(segment s){ return line::distance(s, c) <= r; }
    bool on(vector2 p){ return vector2::distance(p, c) == r; }
    bool in(vector2 p){ return vector2::distance(p, c) < r; }
    bool in_or_on(vector2 p){ return vector2::distance(p, c) <= r; }

    vector<vector2> tangent_points(vector2 p){  // positive from circle
        if (in(p)) return {};
        scalar a = c.angle_to(p);
        scalar da = acos(r / vector2::distance(c, p));
        if (da == 0) return { point(a) };
        return { point(a - da), point(a + da) };
    }

    vector<line> tangents(vector2 p){  // positive from circle
        if (in(p)) return {};
        scalar a = c.angle_to(p);
        if (on(p)) return { tangent(a) };
        scalar da = acos(r / vector2::distance(c, p));
        return { line(segment(p, point(a - da))),
                 line(segment(p, point(a + da))) };
    }

    line tangent_by_circle_point(vector2 p){
        return r == 0 ? line(c, vector2::up()) : line(segment(c,p)).perpendicular_with(p);
    }

    line tangent(scalar a){ return tangent_by_circle_point(point(a)); }

    vector2 point(scalar a){ return c + vector2::by_angle_and_distance(a, r); }

    line any_tangent(){ return line(c + vector2::right() * r, vector2::up()); }

    scalar distance(scalar a, scalar b){ return angle(a, b) * r; }
    scalar min_distance(scalar a, scalar b){ return min(distance(a, b), distance(b, a)); }

    scalar distance(vector2 a, vector2 b){ return distance(c.angle_to(a), c.angle_to(b)); }
    scalar min_distance(vector2 a, vector2 b){ return min(distance(a, b), distance(b, a)); }

    scalar area(scalar a, scalar b){ return angle(a, b) * sqr(r) / 2; }
    scalar min_area(scalar a, scalar b){ return min(min_area(a, b), min_area(b, a)); }

    scalar area(vector2 a, vector2 b){ return area(c.angle_to(a), c.angle_to(b)); }
    scalar min_area(vector2 a, vector2 b){ return min(area(a, b), area(b, a)); }

    scalar area(){ return scalar::PI() * sqr(r); }
    scalar perimeter(){ return scalar::PI() * r * 2; }

    scalar area(scalar a){ return a * sqr(r) / 2; }
    scalar perimeter(scalar a){ return a * r; }

    bool is_intersect(line ln){ return ln.distance_to(c) <= r; }

    vector<vector2> intersection_points(line ln){
        scalar d = ln.distance_to(c);
        if (d > r) return vector<vector2>();
        vector2 o = ln.nearest_point(c);
        if (d == r) return vector<vector2>{ o };
        scalar h = sqrt(r * r - d * d);
        return vector<vector2>{ o.move(ln.d, -h), o.move(ln.d, h) };
    }

    scalar segment_area_by_distance_to_center(scalar d){
        scalar a = 2 * acosl((d / r).v);
        scalar ps = sqrt((r*r-d*d).v);
        return area(a) - d * ps;
    }

    scalar distance_to_center_by_area_ratio(scalar a, scalar b){ // a : b,  a < b
        scalar needseg = area() * a / (a + b);
        scalar left = 0;
        scalar right = r;
        for (int i = 0; i < 128; i++){
            scalar mid = (right + left) / 2;
            scalar seg = segment_area_by_distance_to_center(mid).v;
            if (seg.v > needseg.v) left = mid;
            else right = mid;
        }
        return (left + right) / 2;
    }

    static vector<vector2> intersection_points(circle a, circle b){
        assert(a != b);
        if (a.c == b.c) return vector<vector2>();
        line ln = line::from_ABC(
                (b.c.x - a.c.x) * 2,
                (b.c.y - a.c.y) * 2,
                sqr(a.c.x) - sqr(b.c.x) + sqr(a.c.y) - sqr(b.c.y) + sqr(b.r) - sqr(a.r));
        return a.intersection_points(ln);
    }

    static vector<line> external_tangents(circle a, circle b){
        scalar dist = vector2::distance(a.c, b.c);
        if (a.r > b.r) swap(a, b);
        scalar delta_r = b.r - a.r;
        if (dist < delta_r){
            return {};
        }
        else if (dist == 0){
            return { a.any_tangent() };
        }
        else{
            scalar ang = (b.c).angle_to(a.c);
            scalar d_ang = acos(delta_r / dist); // or -
            vector2 at = a.point(ang);
            vector2 bt = b.point(ang);
            return { line(segment(a.point(ang - d_ang), b.point(ang - d_ang))),
                     line(segment(a.point(ang + d_ang), b.point(ang + d_ang))) };
        }
    }

    static vector<line> internal_tangents(circle a, circle b){
        segment s(a.c, b.c);
        if (s.length() < a.r + b.r) return {};
        vector2 o = s.ratio(a.r, b.r);
        return a.tangents(o);
    }

    static vector<line> tangents(circle a, circle b){
        vector<line> x = external_tangents(a, b);
        vector<line> y = external_tangents(a, b);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }

    bool operator==(const circle &o) const { return c == o.c && r == o.r; }
    bool operator!=(const circle &o) const { return !((*this) == o); }
};

class polygon{
    vector<vector2> ps;
    int mod(int i) const { return (i % size() + size()) % size(); }

    void delete_unique(){
        vector<vector2> n;
        for (int i = 0; i < size(); i++){
            if (n.size() == 0 || n.back() != ps[i])
                n.pb(ps[i]);
        }
        ps = n;
        while (size() > 0 && ps.back() == ps.front())
            ps.pop_back();
    }

    void delete_3_on_line(){
        vector<vector2> n;
        for (int i = 0; i < size(); i++){
            if (!line(segment(get_point(i - 1), get_point(i))).contains(get_point(i + 1)))
                n.pb(get_point(i));
        }
        ps = n;
    }

    // против часовой стрелки - positive
    bool is_positive(){ return is_zero() || line(segment(get_point(0), get_point(1))).is_point_left(get_point(2)); }
    bool is_negative(){ return !is_positive(); }
    void simplify(){ delete_unique(); delete_3_on_line(); make_positive(); }
    void make_positive(){ if (is_negative()) reverse(ps.begin(), ps.end()); }
public:
    polygon() {}
    polygon(vector<vector2> ps) : ps(ps) { simplify(); }

    void read(istream &stream, int n){
        for (int i = 0; i < n; i++){
            vector2 t;
            stream >> t;
            ps.pb(t);
        }
        simplify();
    }

    friend ostream& operator<<(ostream &stream, const polygon &v) {
        stream << "{ polygon : ";
        for (int i = 0; i < v.size(); i++){
            stream << v.get_point(i) << (i == v.size() - 1 ? "" : ", ");
        }
        stream << " }";
        return stream;
    }

    bool is_zero() { return size() == 0; }
    int size() const { return ps.size(); }
    vector2 get_point(int i) const { return ps[mod(i)]; }
    segment get_segment(int i) { return segment(ps[mod(i)], ps[mod(i + 1)]); }
    vector<vector2> get_points() const { return ps; }
    vector<segment> get_segments() const {
        vector<segment> ss;
        for (int i = 0; i < size(); i++)
            ss.pb(segment(get_point(i),get_point(i + 1)));
        return ss;
    }

    void rotate_around(vector2 center, scalar a){ for (int i = 0; i < size(); i++) ps[i] = ps[i].rotate_around(center, a); }

    void move(vector2 delta) {
        for (int i = 0; i < size(); i++){
            ps[i] = ps[i] + delta;
        }
    }

    scalar perimeter(){ scalar p = 0; for (segment s : get_segments()) p += s.length(); return p; }

    scalar area(){
        scalar area = 0;
        for (segment s : get_segments()){
            area += (s.p2.x - s.p1.x) * (s.p1.y + s.p2.y);
        }
        return area / 2;
    }

    polygon right_part(line ln){ // need delete_unique after and init_all before
        vector<vector2> pps;
        for (int i = 0; i < size(); i++){
            if (ln.is_point_right(get_point(i)))
                pps.pb(get_point(i));
            if (ln.is_intersect(get_segment(i))){
                pps.pb(ln.intersection_point(get_segment(i)));
            }
        }
        return polygon(pps);
    }

    polygon left_part(line ln){ return right_part(ln.reversed()); }

    vector<polygon> break_into_triangles(){
        vector<polygon> ans;
        for (int i = 1; i < size() - 1; i++){
            vector<vector2> t;
            t.pb(ps[0]);
            t.pb(ps[i]);
            t.pb(ps[i+1]);
            ans.pb(polygon(t));
        }
        return ans;
    }

    bool operator==(const polygon &p) const {
        if (size() != p.size()) return false;
        if (size() == 0) return true;
        for (int i = 0; i < size(); i++){
            if (get_point(0) == p.get_point(i)){
                for (int j = 0; j < size(); j++){
                    if (get_point(j) != p.get_point(i + j)) return false;
                }
                return true;
            }
        }
        return false;
    }

    bool operator!=(const polygon &p) const { return !((*this) == p); }

    polygon operator*(const polygon &p) const { polygon ans(p); for (segment s : get_segments()) ans = ans.left_part(
                    line(s)); return ans; }

    static polygon convex_hull(vector<vector2> a){
        polygon p;
        vector<vector2> s1,s2;
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++){
            while(s1.size() > 1 && s1[s1.size()-1] != a[i] &&
                  !line(segment(s1[s1.size()-2],s1[s1.size()-1])).is_point_left(a[i])) {
                s1.pop_back();
            }
            if (s1.size() == 0 || s1[s1.size()-1] != a[i])
                s1.push_back(a[i]);
        }
        for (int i = 0; i < a.size(); i++){
            while(s2.size() > 1 && s2[s2.size()-1] != a[i] &&
                  !line(segment(s2[s2.size()-2],s2[s2.size()-1])).is_point_right(a[i])) {
                s2.pop_back();
            }
            if (s2.size() == 0 || s2[s2.size() - 1] != a[i])
                s2.push_back(a[i]);
        }
        for (int i = s2.size() - 2; i > 0; i--){
            s1.push_back(s2[i]);
        }
        return polygon(s1);
    }

    static scalar sum_area(polygon a, polygon b){ return a.area() + b.area() - (a * b).area(); }
    static scalar sum_perimeter(polygon a, polygon b){ return a.perimeter() + b.perimeter() - (a * b).perimeter(); }
};

int main() {
    fast_io; setp(8);

    circle c1, c2;
    scalar a1, b1, a2, b2;

    int t;
    cin >> t;
    while(t--){
        cin >> c1 >> a1 >> b1;
        cin >> c2 >> a2 >> b2;

        c1 = circle(c1.c, c1.distance_to_center_by_area_ratio(a1, b1));
        c2 = circle(c2.c, c2.distance_to_center_by_area_ratio(a2, b2));

        auto tns = circle::tangents(c1, c2);
        if (tns.empty()){
            println(0,0,0);
        }
        else{
            random_shuffle(all(tns));
            line ln = tns[0].normalized();
            println(ln.A(), ln.B(), ln.C());
        }
    }
    return 0;
}