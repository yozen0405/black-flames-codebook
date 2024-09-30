void dfs(int u) {
    while(G[u].size()) {
        auto [v, eid] = G[u].back();
        G[u].pop_back();

        if (vis[eid]) continue;

        vis[eid] = 1;
        dfs(v);
        ans.pb(id);
    }
}