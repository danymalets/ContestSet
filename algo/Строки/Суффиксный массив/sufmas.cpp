#pragma region TEMPLATE

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define fast_io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define erun(x) (x).erase(unique(all(x)),(x).end())
#define sp(x) setprecision(x) << fixed
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



const int MIN_CHAR = 'a';
const int MAX_CHAR = 'z';

struct sufmas{ // O(n log n)
    string s;        //  abab
    vector<int> p;   //  0231  - index in sorted array
    vector<int> c;   //  0101  - cost

    sufmas() {}

    sufmas(string s){
        this->s = s;
        solve();
    }

    int length(){ return s.length(); }

private:
    void solve(){
        p.resize(length());
        c.resize(length());
        int alf = MAX_CHAR - MIN_CHAR + 1;
        vector<int> cnt(alf);
        for (int i = 0; i < length(); i++)
            cnt[s[i] - MIN_CHAR]++;
        for (int i = 1; i < alf; i++)
            cnt[i] += cnt[i-1];
        for (int i=0; i<length(); i++)
            p[--cnt[s[i] - MIN_CHAR]] = i;
        c[p[0]] = 0;
        int levels = 1;
        for (int i=1; i<length(); i++) {
            if (s[p[i]] != s[p[i-1]])  levels++;
            c[p[i]] = levels - 1;
        }
        vector<int> cn(length());
        vector<int> pn(length());
        for (int h = 0; (1 << h) < length(); h++) {
            for (int i = 0; i<length(); i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0)  pn[i] += length();
            }
            fill(cnt.begin(), cnt.begin() + levels, 0);
            for (int i = 0; i < length(); i++)
                cnt[c[pn[i]]]++;
            for (int i = 1; i < levels; i++)
                cnt[i] += cnt[i - 1];
            for (int i = length() - 1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            levels = 1;
            for (int i = 1; i < length(); i++) {
                int m1 = (p[i] + (1 << h)) % length(),  m2 = (p[i - 1] + (1 << h)) % length();
                if (c[p[i]] != c[p[i - 1]] || c[m1] != c[m2])
                    ++levels;
                cn[p[i]] = levels - 1;
            }
            c = cn;
        }
    }
};

int main() {
    fast_io;

    sufmas sf("abab");
    printvln(sf.p);
    printvln(sf.c);


    return 0;
}

