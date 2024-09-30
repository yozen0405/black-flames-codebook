bool SPFA(int s) {
    vector<int> dis(n, INF);
    vector<bool> inq(n);
    vector<int> cnt(n);

    queue<int> q;
    q.push(s);
    dis[s] = 0;
    inq[s] = true;

    while (q.size()) {
        int u = q.front();
        q.pop();
        cnt[u]++;

        if (cnt[u] == n) {
            // negative cycle
            return true;
        }

        inq[u] = false;

        for (auto [v, w] : G[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;

                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }

    return false;
}