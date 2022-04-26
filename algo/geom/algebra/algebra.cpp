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

int bin_pow(int x, ll n, int mod){
    if (n == 0) return 1 % mod;
    if (n % 2 == 1) return 1LL * bin_pow(x, n - 1, mod) * x % mod;
    int t = bin_pow(x, n / 2, mod);
    return t * t % mod;
}

void print() { }
template<typename First, typename... Strings>
void print(First arg, const Strings&... rest) {
    cout << arg << " "; print(rest...);
}

void println() { cout << '\n'; }
template<typename First, typename... Strings>
void println(First arg, const Strings&... rest) {
    cout << arg << " "; println(rest...);
}

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



bool is_prime(int n) { int s = sqrt(n); for (int i = 2; i <= s; i++) if (n % i == 0) return false; return true; }
bool is_prime(ll n) { int s = sqrt(n); for (int i = 2; i <= s; i++) if (n % i == 0) return false; return true; }

vector<int> factorize(int n) { // n>=2
    vector<int> ans;
    for (int i = 2; i * i <= n; i++){
        while (n % i == 0){
            ans.pb(i);
            n /= i;
        }
    }
    if (n != 1) ans.pb(n);
    return ans;
}

vector<ll> factorize(ll n) { // n>=2
    vector<ll> ans;
    for (int i = 2; 1LL * i * i <= n; i++){
        while (n % i == 0){
            ans.pb(i);
            n /= i;
        }
    }
    if (n != 1) ans.pb(n);
    return ans;
}

vector<int> get_divizors(int n){ // sorted, O(sqrt(n)), 1 <= n <= 2e9
    vector<int> ans;
    for (int i = 1; i * i < n; i++) if (n % i == 0) ans.pb(i);
    int sz = ans.size();
    int s = sqrt(n); if (s * s == n) ans.pb(s);
    for (int i = sz - 1; i >= 0; i--) ans.pb(n / ans[i]);
    return ans;
}

vector<ll> get_divizors(ll n){ // sorted, O(sqrt(n)), 1 <= n <= 4e18
    vector<ll> ans;
    for (int i = 1; 1LL * i * i < n; i++) if (n % i == 0) ans.pb(i);
    int sz = ans.size();
    int s = sqrt(n); if (1LL * s * s == n) ans.pb(s);
    for (int i = sz - 1; i >= 0; i--) ans.pb(n / ans[i]);
    return ans;
}

const int MAX_PRIME = 1e6;

bool prime[MAX_PRIME+1];

void init_prime(){
    fill(prime + 2, prime + MAX_PRIME + 1, true);
    for (int i = 2; i * i <= MAX_PRIME; i++){
        if (prime[i]){
            for (int j = i * i; j <= MAX_PRIME; j += i){
                prime[j] = false;
            }
        }
    }
}


vector<pair<char, int>> tov(string s){
    vector<pair<char, int>> ans;
    int t = 0;
    for (int i = 0; i < s.length(); i++){
        if (i == (int)s.length() - 1 || s[i] != s[i+1]){
            ans.pb({s[i], t+1});
            t = 0;
        }
        else {
            t++;
        }
    }
    return ans;
}

int main() {
    fast_io;
    init_prime();
    for (int i = 0; i < 10; i++){
        if (prime[i]) println(i);
    }


    return 0;
}