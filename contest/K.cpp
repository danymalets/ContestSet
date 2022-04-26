#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

/*
 *
 *    | a, b |
 *    | c, d |
 *
 */
struct matrix2x2{
    int a, b;
    int c, d;

    matrix2x2(int a, int b, int c, int d){
        this->a = a; this->b = b;
        this->c = c; this->d = d;
    }

    matrix2x2 operator*(matrix2x2 o) {
        return matrix2x2((1LL * a * o.a + 1LL * b * o.c) % MOD,(1LL * a * o.b + 1LL * b * o.d) % MOD,
                         (1LL * c * o.a + 1LL * d * o.c) % MOD,(1LL * c * o.b + 1LL * d * o.d) % MOD);
    }

    static matrix2x2 bin_pow(matrix2x2 a, long long n){
        if (n == 0)
            return matrix2x2(1, 0,
                             0, 1);
        if (n % 2 == 1)
            return bin_pow(a, n-1) * a;
        matrix2x2 t = bin_pow(a, n / 2);
        return t * t;
    }
};

int get_nth_fib(long long n){
    return matrix2x2::bin_pow(matrix2x2(0, 1,
                                           1, 1), n).a;
}

int main() {
    long long n;
    cin >> n;
    cout << get_nth_fib(n);
    return 0;
}