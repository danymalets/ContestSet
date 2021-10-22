#include <iostream>
#include <queue>
using namespace std;

const int INF = 2e9;
const long long LLINF = 4e18;
const int V = 602;

int cntv;
bool used[V];
int from[V];
long long flow[V][V], capacity[V][V], cost[V][V], pot[V], dist[V];

bool find_way(int source, int target) {
    fill(used, used + cntv, false);
    fill(dist, dist + cntv, LLINF);
    dist[source] = 0;
    for (int i = 0; i < cntv; i++){
        int u = -1;
        long long mn = INF;
        for (int v = 0; v < cntv; v++){
            if (!used[v] && dist[v] < mn){
                u = v;
                mn = dist[v];
            }
        }
        if (dist[u] == INF) break;
        used[u] = true;
        for (int v = 0; v < cntv; v++){
            if (pot[v] == LLINF) continue;
            if (capacity[u][v] - flow[u][v] <= 0) continue;
            if (dist[v] > dist[u] + pot[u] - pot[v] + cost[u][v]){
                dist[v] = dist[u] + pot[u] - pot[v] + cost[u][v];
                from[v] = u;
            }
        }
    }
    return dist[target] < LLINF;
}

long long mincost_maxflow(int source, int target) {
    fill(pot, pot + cntv, LLINF);
    pot[source] = 0;
    from[source] = -1;
    while (true){
        bool found = false;
        for (int u = 0 ; u < cntv; u++){
            if (pot[u] == LLINF) continue;
            for (int v = 0 ; v < cntv; v++){
                if (capacity[u][v] - flow[u][v] > 0 && pot[v] > pot[u] + cost[u][v]){
                    pot[v] = pot[u] + cost[u][v];
                    found = true;
                }
            }
        }
        if (!found) break;
    }
    long long ans = 0;
    while (find_way(source, target)) {
        for (int v = 0; v < cntv; v++){
            if (pot[v] != LLINF){
                pot[v] += dist[v];
            }
        }
        long long delta = INF;
        for (int v = from[target], to = target; v >= 0; to = v, v = from[v]){
            delta = min(delta, capacity[v][to] - flow[v][to]);
        }
        for (int v = from[target], to = target; v >= 0; to = v, v = from[v]){
            flow[v][to] += delta;
            flow[to][v] -= delta;
            ans += cost[v][to] * delta;
        }
    }
    return ans;
}

void add_edge(int u, int v, long long _cap, long long _cost){
    capacity[u][v] = _cap;
    cost[u][v] = _cost;
    capacity[v][u] = 0;
    cost[v][u] = -_cost;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n, m, s, t;
    cin >> n >> m;
    s = 0;
    t = 1 + n + m;
    cntv = n + m + 2;
    for (int i = 0; i < n; i++){
        int w;
        cin >> w;
        add_edge(s, 1 + i, w, 0);
    }
    for (int i = 0; i < m; i++){
        int w;
        cin >> w;
        add_edge(1 + n + i, t, w, 0);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int c;
            cin >> c;
            add_edge(1 + i, 1 + n + j, INF, c);
        }
    }
    cout << mincost_maxflow(s, t);
    return 0;
}
