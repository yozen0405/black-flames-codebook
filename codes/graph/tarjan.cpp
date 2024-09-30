const int N = 5e5 + 5;
int n, m, stamp;
vector<int> G[N];
int dfn[N], low[N]; 
vector<vector<int>> bcc;
stack<int> stk;

void dfs (int u, int par) {
    dfn[u] = low[u] = ++stamp; 
    stk.push(u);
    int cnt = 0; // 兒子個數
    for (auto v : G[u]) {
        if (v == par) continue; 
        if (!dfn[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            cnt++;
            if (low[v] >= dfn[u]) { // 若 u 為割點
                int now = 0;
                bcc.push_back({});
                do {
                    now = stk.top();
                    stk.pop();
                    bcc.back().push_back(now);
                } while (now != v);
                bcc.back().push_back(u);
            }
        } else {
            low[u] = min(low[u], dfn[v]); 
        }
    }
    // 特判孤立點
    if (par == 0 && cnt == 0) {
        bcc.push_back({u});
        return;
    }
}