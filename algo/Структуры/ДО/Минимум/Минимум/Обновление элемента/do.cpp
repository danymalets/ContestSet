#include<bits/stdc++.h>
using namespace std;

const int INF=2e9;
const int N=1e5;


class tree {
private:

    // CHANGE ONLY THIS PART
    //----------------------------------------------------

    typedef int tree_vertex;

    tree_vertex combine(tree_vertex a, tree_vertex b){
        return min(a, b);
    }

    //----------------------------------------------------

    vector<tree_vertex> t;

    void build(vector<tree_vertex> &a, int v, int tl, int tr) {
        if (tl == tr) t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) return INF;
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return combine(get(v * 2, tl, tm, l, min(tm, r)), get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) t[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v * 2, tl, tm, pos, val);
            else update(v * 2 + 1, tm + 1, tr, pos, val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
public:
    int n;

    tree(vector<tree_vertex> &a) : n(a.size()) {
        t.resize(4 * n);
        build(a, 1, 0, n);
    }

    tree_vertex get(int l, int r){ return get(1, 0, n, l, r); }
    void update(int pos, tree_vertex val){ update(1, 0, n, pos, val); }
};

int main(){

    return 0;
}
