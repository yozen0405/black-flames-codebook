#include<bits/stdc++.h>
#define int long long

using namespace std;

using Graph = vector<vector<int>>;

struct DSU {
    int cc;
    vector<int> par, sz;
    vector<set<int>> S;

    DSU(int n = 0) : cc(n), par(n), sz(n, 1), S(n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        for (int x : S[v]) {
            S[u].insert(x);
        }
        S[v].clear();
        cc--;
        return true;
    }
};

struct Edge {
    int u, v;
    int cost;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

const int INF = 2e18;

// 對於目前選到的每個集合，選他周圍的最小邊
int MST(int n, vector<Edge> edges) {
    int m = edges.size();

    DSU dsu(n);
    vector<Edge> nei(n);

    int mst_ans = 0;

    int conti = true;
    while (conti) {
        conti = false;
        fill(nei.begin(), nei.end(), Edge{-1, -1, INF});

        for (auto [u, v, cost] : edges) {
            int fu = dsu.find(u), fv = dsu.find(v);
            if (fu == fv) continue;

            nei[fu] = min(nei[fu], {u, v, cost});
            nei[fv] = min(nei[fv], {v, u, cost});
        }

        for (int i = 0; i < n; i++) {
            auto e = nei[i];
            if (e.u == -1) continue;
            if (dsu.find(e.u) != dsu.find(e.v)) {
                dsu.merge (e.u, e.v);
                mst_ans += e.cost;
                conti = true;
            }
        }
    }

    return mst_ans;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({u, v, w});
    }

    cout << MST(n, edges) << "\n";
}