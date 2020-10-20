vector<int> Centroid(const vector<vector<int>> &g) {
	        int n = g.size()-1;
	        vector<int> centroid;
	        vector<int> sz(n+1);
	        function<void (int, int)> dfs = [&](int u, int prev) {
	                sz[u] = 1;
	                bool is_centroid = true;
	                for (auto v : g[u]) if (v != prev) {
	                        dfs(v, u);
	                        sz[u] += sz[v];
	                        if (sz[v] > n / 2) is_centroid = false;
	                }
	                if (n - sz[u] > n / 2) is_centroid = false;
	                if (is_centroid) centroid.push_back(u);
	        };
	        dfs(1, -1);
	        return centroid;
}