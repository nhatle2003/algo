struct Dinic{
    int s, t, sz;

    vector<array<int, 4>> edges;
    vector<vector<int>> adj;
    vector<int> level, pt;
    Dinic(int _s, int _t, int _sz) : s(_s), t(_t), sz(_sz) {
        adj.resize(sz + 5), level.resize(sz + 5), pt.resize(sz + 5);
    }

    Dinic() : s(1000), t(1000), sz(1000) {
        adj.resize(sz + 5), level.resize(sz + 5), pt.resize(sz + 5);
    }
    inline void add_edge(int u, int v, int c){
        adj[u].push_back(edges.size()); edges.push_back({u, v, 0, c});
        adj[v].push_back(edges.size()); edges.push_back({v, u, 0, 0});
    }

    int bfs(int lim){
        fill(level.begin(), level.begin() + sz + 1, 0);
        queue<int> q; q.push(s);
        level[s] = 1;
        while(!q.empty()){
            int i = q.front(); q.pop();
            for(int id : adj[i]){
                int x = edges[id][1], f = edges[id][2], c = edges[id][3];
                if(f + lim > c || level[x]) continue;
                level[x] = level[i] + 1;
                q.push(x);
            }
        }
        return level[t];
    }
    int dfs(int i, int w){
        if(w == 0) return 0;
        if(i == t) return w;
        for(int &j = pt[i]; j < adj[i].size(); j++){
            int id = adj[i][j];
            int x = edges[id][1], f = edges[id][2], c = edges[id][3];
            if(level[x] != level[i] + 1 || c == f) continue;
            int curflow = dfs(x, min(w, c - f));
            if(curflow == 0) continue;
            edges[id][2] += curflow;
            edges[id ^ 1][2] -= curflow;
            // cout << i << " " << x << "  ::  " << curflow << endl;
            return curflow;
        }
        return 0;
    }
    int maxFlow(){
        int ans = 0;
        for(int lim = 30; lim >= 0; lim--){
            while(bfs(1 << lim)){
                fill(pt.begin(), pt.begin() + sz + 1, 0);
                int add;
                while((add = dfs(s, INF))) ans += add;
            }
        }
        return ans;
    }
};
