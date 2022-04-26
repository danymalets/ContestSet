#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <random>
#include <string>
#include <iomanip>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef long double ld;

#define fast_io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define erase_unique(x) (x).erase(unique(all(x)),(x).end())
#define sp(x) setprecision(x) << fixed
#define all(x) (x).begin(),(x).end()
#define dcl(x,y) (x%y?x/y+1:x/y)
#define cube(x) ((x)*(x)*(x))
#define sqr(x) ((x)*(x))
#define bg1 cout << '!'
#define bg2 cout << '?'
#define ln cout << '\n'
#define pb push_back
#define mp make_pair
#define endl '\n'
#define file_all file_in,file_out
#define file_in freopen("input.txt","rt",stdin)
#define file_out freopen("output.txt","wt",stdout)


const ll LLINF = 8e18;
const int MOD = 1e9;
const int INF = 2e9;
const int MSIZE = 2;
const long long M = 1e18;

class Array{
public:
    int a[MSIZE];

public:
    Array(){
        for (int i = 0; i < MSIZE; i++){
            a[i] = 0;
        }
    }

    int& at(int i){
        return a[i];
    }

    void set_val(int i, int val){
        a[i] = val;
    }

    int get_val(int i){
        return a[i];
    }
};

class Matrix{
public:
    int a[MSIZE][MSIZE];

public:
    Matrix(){
        for (int i = 0; i < MSIZE; i++){
            for (int j = 0; j < MSIZE; j++){
                a[i][j] = 0;
            }
        }
    }

    int& at(int i, int j){
        return a[i][j];
    }

    void set_val(int cur, int pre, int val = 1){
        at(cur, pre) = val;
    }

    static Matrix E(){
        Matrix ans;
        for (int i = 0; i < MSIZE; i++){
            ans.at(i, i) = 1;
        }
        return ans;
    }
};

Matrix mult(Matrix a, Matrix b){
    Matrix ans;
    for (int i = 0; i < MSIZE; i++){
        for (int j = 0; j < MSIZE; j++){
            for (int k = 0; k < MSIZE; k++){
                ans.at(i, j) = (0LL + ans.at(i, j) + 1LL * a.at(i, k) * b.at(k, j)) % MOD;
            }
        }
    }
    return ans;
}

Array mult(Matrix mt, Array a){
    Array ans;
    for (int i = 0; i < MSIZE; i++){
        for (int k = 0; k < MSIZE; k++){
            ans.at(i) = (0LL + ans.at(i) + 1LL * a.at(k) * mt.at(i, k)) % MOD;
        }
    }
    return ans;
}

Matrix bin_pow(Matrix mt, long long n){
    Matrix ans = Matrix::E();
    vector<bool> vb;
    while(n > 0){
        if (n % 2 == 1){
            vb.push_back(true);
            n--;
        }
        else{
            vb.push_back(false);
            n /= 2;
        }
    }
    reverse(vb.begin(), vb.end());
    for (bool b: vb){
        if (b) ans = mult(ans, mt);
        else ans = mult(ans, ans);
    }
    return ans;
}

Array solve(Array a, Matrix mt, long long n){
    Matrix ans = bin_pow(mt, n);
    return mult(ans, a);
}

int main(){
    Array a;
    a.set_val(0, 0);
    a.set_val(1, 1);

    Matrix mt;
    mt.set_val(0, 1);
    mt.set_val(1, 1);
    mt.set_val(1, 0);

    long long n;
    cin >> n;
        cout << solve(a, mt, n).get_val(0);
    }
    else{
        n = -n;
        if (n % 2 == 0){
            cout << (-solve(a, mt, n).get_val(0) + MOD) % MOD;
        }else{
            cout << solve(a, mt, n).get_val(0);
        }
    }

    return 0;
}
