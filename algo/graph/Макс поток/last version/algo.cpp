#include <iostream>
#include <queue>
using namespace std;

const long long INF = 4e18;
const int N = 1e3;
const int M = 1e4;

bool used[N];
int n, m, source, target;
int u[M], v[M], w[M], from[N];
long long g[N][N], f[N][N];
queue<int> q;

bool find_way(int source, int sink){
    fill(used, used + n, false);
    q.push(source);
    used[source] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for (int to = 0; to < n; to++){
            if (!used[to] && g[v][to] > 0){
                from[to] = v;
                used[to] = true;
                if (to == sink){
                    while(!q.empty()) q.pop();
                    return true;
                }
                q.push(to);
            }
        }
    }
    return false;
}

long long find_max_flow(int source, int target){
    long long maxflow = 0;
    while(find_way(source, target)){
        long long delta = INF;
        for (int v = from[target], to = target; v >= 0; to = v, v = from[v]){
            delta = min(delta, g[v][to]);
        }
        for (int v = from[target], to = target; v >= 0; to = v, v = from[v]){
            g[v][to] -= delta;
            g[to][v] += delta;
        }
        maxflow += delta;
    }
    return maxflow;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("flow.in", "rt", stdin);
    //freopen("flow.out", "wt", stdout);
    cin >> n >> m >> source >> target;
    source--; target--;
    from[source] = -1;
    for (int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
        if (u[i] == v[i]) continue;
        g[u[i]][v[i]] += w[i];
        f[u[i]][v[i]] += w[i];
    }

    cout << find_max_flow(source, target) << '\n';
    for (int u = 0; u < n; u++){
        for (int v = 0; v < n; v++){
            f[u][v] = max(0LL, f[u][v] - g[u][v]);
        }
    }

    for (int i = 0; i < m; i++){
        cout << min((long long)w[i], f[u[i]][v[i]]) << '\n';
        f[u[i]][v[i]] -= min((long long)w[i], f[u[i]][v[i]]);
    }
    return 0;
}
