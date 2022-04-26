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

const ll LLINF=8e18;
const int MOD=2e9;
const int INF=2e9;



static const int MAX_LENGTH = 1e6;
static const int MODS_SIZE = 3;

static const char MIN_CHAR = 33;
static const int MAX_CHAR = 127;

static const int MIN_MOD = 1e9;
static const int MAX_MOD = 2e9;

int P;

int MODS[MODS_SIZE];
int POWS[MODS_SIZE][MAX_LENGTH];

class hash_string{ // prime

    static void init_mods(){
        srand(time(0));
        for (int i = 0; i < MODS_SIZE; i++){
            int mod;
            do{
                mod = get_random_mod();
            } while (count(MODS, MODS + i, mod));
            MODS[i] = mod;
        }
    }

    static void init_p(){
        P = MAX_CHAR - MIN_CHAR + 5;
        while (!is_prime(P)) P++;
    }

    static void init_pows(){
        for (int i = 0; i < MODS_SIZE; i++){
            POWS[i][0] = 1;
            for (int j = 1; j < MAX_LENGTH; j++){
                POWS[i][j] = 1LL * POWS[i][j - 1] * P % MODS[i];
            }
        }
    }

    static int get_random_mod(){
        int r = rand() % (MAX_MOD - MIN_MOD) + MIN_MOD;
        while (!is_prime(r)) r++;
        return r;
    }

    static bool is_prime(int n) {
        int s = sqrt(n);
        for (int i = 2; i <= s; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    string s;
    vector<int> hashes[MODS_SIZE];

    void self_init(){
        size = s.length();
        for (int i = 0; i < MODS_SIZE; i++){
            if (size > 0) {
                hashes[i].resize(size);
                hashes[i][0] = s[0] - MIN_CHAR + 1;
            }
            for (int j = 1; j < size; j++){
                hashes[i][j] = (0LL + hashes[i][j - 1] + 1LL * POWS[i][j] * (s[j] - MIN_CHAR + 1)) % MODS[i];
            }
        }
    }
public:
    static void init(){
        init_mods();
        init_p();
        init_pows();
    }

    int size;


    hash_string() { }

    hash_string(string s){ // [l, r)
        this->s = s;
        self_init();
    }

    vector<int> get_hash(int l, int r){
        vector<int> ans(MODS_SIZE);
        for (int i = 0; i < MODS_SIZE; i++){
            ans[i] = get_hash(l, r, i);
        }
        return ans;
    }

    int get_hash (int l, int r, int ind_mod) const{ // [l, r)
        return (0LL + hashes[ind_mod][r - 1] - (l > 0 ? hashes[ind_mod][l - 1] : 0) + MODS[ind_mod]) % MODS[ind_mod];
    }

    static bool is_equal(const hash_string &s1, int l1, int r1, const hash_string &s2, int l2, int r2){ // [l, r)
        if (r2 - l2 != r1 - l1) return false;
        for (int i = 0; i < MODS_SIZE; i++){
            if (1LL * s1.get_hash(l1, r1, i) * POWS[i][l2] % MODS[i] !=
                1LL * s2.get_hash(l2, r2, i) * POWS[i][l1] % MODS[i])
                return false;
        }
        return true;
    }

    static int max_pref(const hash_string &s1, int p1, const hash_string &s2, int p2, int maxlen = -1){
        int l = 0;
        int r = min(s1.size - p1 + 1, s2.size - p2 + 1);
        while (l + 1 < r){
            int m = (l + r) / 2;
            if (is_equal(s1, p1, p1 + m, s2, p2, p2 + m))
                l = m;
            else
                r = m;
        }
        return l;
    }

    /*
     * -1   ->   s1(l1,r1) < s2(l2, r2)
     * 0    ->   s1(l1,r1) = s2(l2, r2)
     * 1    ->   s1(l1,r1) > s2(l2, r2)
     */
    static int compare(const hash_string &s1, int l1, int r1, const hash_string &s2, int l2, int r2) {
        int len = min(max_pref(s1, l1, s2, l2), min(r1 - l1, r2 - l2));
        int i1 = l1 + len;
        int i2 = l2 + len;
        if (i1 >= r1 && i2 >= r2) return 0;
        if (i1 >= r1) return -1;
        if (i2 >= r2) return 1;
        if (s1.s[i1] < s2.s[i2]) return -1;
        else return 1;
    }

    static int compare(const hash_string &s1, const hash_string &s2) {
        return compare(s1, 0, s1.size, s2, 0, s2.size);
    }

    friend istream& operator>>(istream &stream, hash_string &hs) {
        stream >> hs.s;
        hs.self_init();
        return stream;
    }
    friend ostream& operator<<(ostream &stream, const hash_string &hs) { return stream << hs.s; }

    bool operator<(const hash_string &hs) const { return compare(*this, hs) == -1; }
    bool operator==(const hash_string &hs) const { return compare(*this, hs) == 0; }
    bool operator!=(const hash_string &hs) const { return compare(*this, hs) != 0; }
    bool operator>(const hash_string &hs) const { return compare(*this, hs) == 1; }
};

string s;
int n;

hash_string s1, s2;

bool can(int c, int len){
    int l = c - len;
    int r = c + len + 1;
    return hash_string::is_equal(s1, l, r, s2, n - r, n - l);
}

bool can2(int c, int len){
    int l = c - len + 1;
    int r = c + len + 1;
    return hash_string::is_equal(s1, l, r, s2, n - r, n - l);
}


int main()
{
    fast_io;
    hash_string::init();
    cin >> s;
    s1 = hash_string(s);
    reverse(all(s));
    s2 = hash_string(s);

    n = s.length();

    ll ans = 0;
    for (int i = 0; i < n; i++){
        int l = 0;
        int r = min(i, n - i - 1) + 1;

        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (can(i, m)){
                l = m;
            }
            else{
                r = m;
            }
        }
        ans += l + 1;
    }
    for (int i = 0; i < n - 1; i++){
        int l = 0;
        int r = min(i + 1, n - i - 1) + 1;

        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (can2(i, m)){
                l = m;
            }
            else{
                r = m;
            }
        }
        ans += l;
    }

    println(ans);

    return 0;
}
