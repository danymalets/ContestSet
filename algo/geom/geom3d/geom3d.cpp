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
        return (*this) >= mn && (*this) <= mx;
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
        scalar ans = (a % m + m) % m;
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

struct vector3{
    scalar x, y, z;

    vector3() {}
    vector3(scalar x, scalar y, scalar z) : x(x), y(y), z(z) {}

    friend istream& operator>>(istream &stream, vector3 &v) { return stream >> v.x >> v.y >> v.z; }
    friend ostream& operator<<(ostream &stream, const vector3 &v) { return stream << "(" << v.x << ", " << v.y << ", " << v.z << ")"; }

    bool operator==(const vector3 &v) const { return x == v.x && y == v.y && z == v.z; }
    bool operator!=(const vector3 &v) const { return !(*this == v); }
    bool operator<(const vector3 &v) const {
        return x.v == v.x.v ? (y.v == v.y.v ? z.v < v.z.v : y.v < v.y.v) : x.v < v.x.v;
    }

    vector3 any_orthogonal(){ return x == 0 ? vector3(0, z, -y) : vector3(y, -x, 0); }

    scalar sqr_magnitude(){ return x * x + y * y + z * z; }
    scalar magnitude(){ return sqrt(sqr_magnitude()); }
    vector3 normalized(){ return new_with_length(1); }
    vector3 new_with_length(scalar new_len){
        scalar len = magnitude();
        return vector3(x * new_len / len, y * new_len / len, y * new_len / len);
    }

    vector3 operator+(const vector3 &v) const { return vector3(x + v.x, y + v.y, z + v.z); }
    vector3 operator-(const vector3 &v) const { return vector3(x - v.x, y - v.y, z - v.z); }
    vector3 operator*(const vector3 &v) const { return vector3(x * v.x, y * v.y, z * v.z); }
    vector3 operator*(const scalar &t) const { return vector3(x * t, y * t, z * t); }
    vector3 operator/(const vector3 &v) const { return vector3(x / v.x, y / v.y, z / v.z); }
    vector3 operator/(const scalar &t) const { return vector3(x / t, y / t, z / t); }
    vector3 operator-() const { return get_reverse(); }
    vector3 get_reverse() const { return vector3(-x, -y, -z); }

    static scalar scalar_product(vector3 a, vector3 b){ vector3 c = a * b; return c.x + c.y + c.z; }
    static scalar scalar_product(vector3 a, vector3 b, vector3 c){
        return scalar_product(a, cross_product(b, c));
    }

    static scalar angle(vector3 a, vector3 b){ return acos((scalar_product(a,b) / (a.magnitude() * b.magnitude()))); }
    static bool is_orthogonal(vector3 a, vector3 b){ return scalar_product(a,b) == 0; }

    static vector3 cross_product(vector3 a, vector3 b){
        return vector3(
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x
        );
    } // Ox * Oy = Oz

    static bool is_same_direction(vector3 a, vector3 b) { return is_parallel(a, b) && scalar_product(a,b) > 0; }
    static bool is_opposite_direction(vector3 a, vector3 b) { return is_parallel(a, b) && scalar_product(a,b) < 0; }

    static bool is_opposite(vector3 a, vector3 b) { return a == -b; }

    static bool is_parallel(vector3 a, vector3 b){ return cross_product(a,b) == vector3::zero(); }

    static vector3 O(){ return vector3(0,0,0); }
    static vector3 zero(){ return vector3(0,0,0); }
    static vector3 Ox_one(){ return vector3(1,0,0); }
    static vector3 Oy_one(){ return vector3(0,1,0); }
    static vector3 Oz_one(){ return vector3(0,0,1); }
    static vector3 one(){ return vector3(1,1,1); }
};

struct line3d{
    vector3 p, d;

    line3d() {}
    line3d(vector3 p, vector3 d) : p(p), d(d) {}
    static line3d by_segment(vector3 a, vector3 b) { return line3d(a, b - a); }

    friend istream& operator>>(istream &stream, line3d &v) { return stream >> v.p >> v.d; }
    friend ostream& operator<<(ostream &stream, const line3d &v) { return stream << "{ line3d : p = " << v.p << ", d = " << v.d << " }"; }

    line3d normalized() { return line3d(p, d.normalized()); }

    vector3 any_point(int i = 0){ return p + d * i; }

    bool contains(vector3 o) const { return vector3::is_parallel(d, o - p); }

    line3d move(vector3 a){ return line3d(p + a, d); } // in global

    static bool is_parallel(line3d a, line3d b) { return vector3::is_parallel(a.d, b.d); } // equals lines are parallel

    //static bool is_skew(line3d a, line3d b) { return !in_one_plane(a,b); }
    line3d reversed() const { return line3d(p, -d); }

    static bool is_same_or_opposite(line3d a, line3d b){ return is_parallel(a, b) && a.contains(b.p); }
    static bool is_opposite(vector3 a, vector3 b) { return a == -b; }
    bool operator==(const line3d &o) const { vector3::is_same_direction((*this).d, o.d) && contains(o.p); }

    scalar distance_to(vector3 o){ return vector3::cross_product(o - p, d).magnitude() / d.magnitude(); }


    line3d operator-() const { return reversed(); }

    //static bool in_one_plane(line3d a, line3d b){ return is_intersect(a,b) || is_parallel(a, b); }

    static scalar distance(line3d a, line3d b){
        if (is_parallel(a,b)){
            return vector3::cross_product(b.p - a.p, a.d).magnitude() / a.d.magnitude();
        }
        else{
            vector3 t = vector3::cross_product(a.d, b.d);
            return scalar(abs(vector3::scalar_product(b.p - a.p, t))) / t.magnitude();
        }
    }

    static line3d Ox() { return line3d(vector3::O(), vector3::Ox_one()); }
    static line3d Oy() { return line3d(vector3::O(), vector3::Oy_one()); }
    static line3d Oz() { return line3d(vector3::O(), vector3::Oz_one()); }
};

/*
 * (x - p.x) * n.x + (y - p.y) * n.y + (y - p.y) * n.y == 0
 * x * n.x + y * n.y + z * n.z - (p.x * n.x + p.y * n.y + p.z * n.z) == 0
 * x * n.x + y * n.y + z * n.z == p.x * n.x + p.y * n.y + p.z * n.z
 */
struct plane{
    vector3 p, n;

    plane() {}
    plane(vector3 p, vector3 n) : p(p), n(n) {}
    plane(vector3 a, vector3 b, vector3 c) : p(a), n(vector3::cross_product(c - b, b - a)) {}
    plane(line3d a, line3d b): p(a.p), n(vector3::cross_product(a.d, b.d)) {}

    scalar A() { return n.x; };        // Ax + By + Сz + D = 0
    scalar B() { return n.y; };
    scalar C() { return n.z; };
    scalar D() { return -vector3::scalar_product(p, n); };

    friend istream& operator>>(istream &stream, plane &pl) { return stream >> pl.p >> pl.n; }
    friend ostream& operator<<(ostream &stream, const plane &pl) { return stream << "{ plane : p = " << pl.p << ", n = " << pl.n << " }"; }

    plane normalized(){ return plane(p, n.normalized()); }

    plane reversed() const { return plane(p, -n); }

    line3d orthogonal_line_with(vector3 o) { return line3d(o, n); }

    vector3 projection(vector3 o){ return intersection_point(orthogonal_line_with(o)); }

    vector3 intersection_point(line3d ln) {
        return ln.p -
            (ln.d * (vector3::scalar_product(ln.p, n) - vector3::scalar_product(p, n)) /
            vector3::scalar_product(ln.d, n));
    }

    bool contains(vector3 o) const { return vector3::is_orthogonal(n, o - p); }

    bool contains(line3d ln){ return contains(ln.any_point(0)) && contains(ln.any_point(1)); }
    bool is_parallel(line3d ln) { return vector3::is_orthogonal(n, ln.d); } // if contains -> parallel
    bool is_intersect(line3d ln) { return !is_parallel(ln); }

    plane parallel_with(vector3 o) { return plane(o, n); }
    plane parallel_with(line3d ln) { return plane(ln.p, n); }


    static bool is_opposite(plane a, plane b){ return a == -b; }
    static bool is_same_or_opposite(plane a, plane b){ return is_parallel(a, b) && a.contains(b.p); }
    bool operator==(const plane &o) const { vector3::is_same_direction((*this).n, o.n) && contains(o.p); }
    plane operator-() const { return reversed(); }

    plane move(scalar d){ return plane(p + n.new_with_length(d), n); }
    plane move(vector3 d){ return plane(p + d, n); }

    scalar distance_to(vector3 o){
        return abs(vector3::scalar_product(n, o) - vector3::scalar_product(n, p)) / n.magnitude();
    }

    bool is_orthogonal_to(line3d ln){ return vector3::is_parallel(n, ln.d); }

    scalar distance_to(line3d ln){ return is_parallel(ln) ? distance_to(ln.p) : 0; }

    static scalar distance(plane a, plane b){ return is_parallel(a,b) ? a.distance_to(b.p) : 0; }

    static bool is_parallel(plane a, plane b){ return vector3::is_parallel(a.n, b.n); } // equals -> parallel
    static bool is_intersect(plane a, plane b){ return !is_parallel(a,b); }

    static line3d intersection_line(plane a, plane b){
        vector3 p = (vector3::scalar_product(a.p, a.n) + vector3::scalar_product(b.p, b.n)) / (a.n + b.n);
    }

    static bool is_intersect(line3d a, line3d b) {
        if (line3d::is_parallel(a, b)) return false;
        if (a.contains(b.p) || a.contains(b.p + b.d)) return true;
        return plane(a.p, a.p + a.d, b.p).contains(b.p + b.d);
    } // 1 point, not equals

    static plane from_ABCD(scalar A, scalar B, scalar C, scalar D){
        vector3 n = vector3(A, B, C);
        scalar k = -D / n.sqr_magnitude();
        return plane(n * k, n);
    }

    static plane Oyz() { return plane(vector3::O(), vector3::Ox_one()); }
    static plane Oxz() { return plane(vector3::O(), vector3::Oy_one()); }
    static plane Oxy() { return plane(vector3::O(), vector3::Oz_one()); }
};

int main() {
    fast_io; setp(2);
    return 0;
}
