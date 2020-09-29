#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


const int N = 1e5;
const ll INF = 1e8;
vector<pair<int,ll>> g[N];
int n;
vector<int> par(N,-1);

void dijkstra(int s, vector<ll>& dis){
	fill(dis.begin() ,dis.end() ,INF);
	set<pair<ll,int>> q; //{distance, node}
	/* insert initial multiple nodes and then relax here
	 if multisource dijkstra instead of just single source, s */
	dis[s] = 0;
	q.insert({0,s});
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		for(auto e : g[v]){
			int to = e.first;
			ll len = e.second;
			if(dis[v] + len < dis[to]){
				q.erase({dis[to], to});
				dis[to] = dis[v] + len;
				par[to] = v;
				q.insert({dis[to], to});
			}
		}
	}
	// for(auto i: dis)cout<<i<<" ";
}

int main(){
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--,b--;
		g[a].pb({b,c});
		g[b].pb({a,c});
	}
	vector<ll> dis(n);
	dijkstra(0, dis);
}