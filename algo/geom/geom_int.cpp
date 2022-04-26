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
#define tests int _t; cin >> _t; while (_t--)
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

struct vector2int{
    int x, y;

    vector2int() {}
    vector2int(int x, int y) : x(x), y(y) {}

    friend istream& operator>>(istream &stream, vector2int &v) { return stream >> v.x >> v.y; }
    friend ostream& operator<<(ostream &stream, const vector2int &v) { return stream << "(" << v.x << ", " << v.y << ")"; }
    vector2int reversed() const { return vector2int(-x, -y); }

    ll sqr_magnitude(){ return 1LL * x * x + 1LL * y * y; }

    vector2int left_perpendicular() { return vector2int(-y, x); }
    vector2int right_perpendicular() { return vector2int(y, -x); }

    bool operator==(const vector2int &v) const { return x == v.x && y == v.y; }
    bool operator!=(const vector2int &v) const { return !(*this == v); }
    bool operator<(const vector2int &v) const { return x == v.x ? y < v.y : x < v.x; }

    vector2int operator+(const vector2int &v) const { return vector2int(x + v.x, y + v.y); }
    vector2int operator-(const vector2int &v) const { return vector2int(x - v.x, y - v.y); }
    vector2int operator*(const vector2int &v) const { return vector2int(x * v.x, y * v.y); }
    vector2int operator*(const int &t) const { return vector2int(x * t, y * t); }
    vector2int operator/(const vector2int &v) const { return vector2int(x / v.x, y / v.y); }
    vector2int operator/(const int &t) const { return vector2int(x / t, y / t); }
    vector2int operator-() const { return reversed(); }

    static bool is_parallel(vector2int a, vector2int b) { return a.x * b.y == a.y * b.x; }

    static bool is_same_direction(vector2int a, vector2int b) { return is_parallel(a, b) && 1LL * a.x * b.x + 1LL * a.y * b.y > 0; }
    static bool is_opposite_direction(vector2int a, vector2int b) { return is_parallel(a, b) && 1LL * a.x * b.x + 1LL * a.y * b.y < 0; }

    static bool is_opposite(vector2int a, vector2int b) { return a == -b; }
    static bool is_perpendicular(vector2int a, vector2int b) { return -a.x * b.y == a.y * b.x; }

    static ll sqr_distance(vector2int x, vector2int y) { return (x - y).sqr_magnitude(); }

    static vector2int O() { return vector2int(0, 0); }
    static vector2int zero() { return vector2int(0, 0); }
    static vector2int right() { return vector2int(1, 0); }
    static vector2int up() { return vector2int(0, 1); }
    static vector2int left() { return vector2int(-1, 0); }
    static vector2int down() { return vector2int(0, -1); }
    static vector2int one() { return vector2int(1, 1); }

    /*
     * vector a->b, c:
     * <0 -> left
     * =0 -> on
     * <0 -> right
     */
    static ll value(vector2int a, vector2int b, vector2int c){
        return 1LL * (b.y - a.y) * (c.x - b.x) - 1LL * (c.y - b.y) * (b.x - a.x) ;
    }

    friend bool third_left(vector2int a, vector2int b, vector2int c){ return value(a, b, c) < 0; }
    friend bool third_on(vector2int a, vector2int b, vector2int c){ return value(a, b, c) == 0; }
    friend bool third_right(vector2int a, vector2int b, vector2int c){ return value(a, b, c) > 0; }
};

ll square(point a, point b, point c){
    point ar[3]{a,b,c};
    ll ans = 0;
    for (int i = 0; i < 3; i++){
        point x = ar[i];
        point y = ar[(i+1)%3];
        ans += 1LL * (x.x - y.x) * (x.y + y.y);
    }
    return abs(ans);
}

int main() {
    fast_io;
    println(third_on(vector2int(0,0), vector2int(1,1), vector2int(2,2)));


    return 0;
}

