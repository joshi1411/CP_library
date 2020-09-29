/* Ashish Joshi
NIT Hamirpur*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = (int)2e5 + 5; //check this 
const int l = 20; //ceil(log2(N))+1
int n;
vector<int> g[N];
int par[l+1][N], depth[N];
int dis[N];

void build(int root = 0){
	memset(par, -1, sizeof par);
	int used[N+5];
	memset(used, 0, sizeof used);
	//bfs
	queue<int> q;
	q.push(root); 
	used[root] = 1;
	while(!q.empty()){
		int i = q.front();
		q.pop();
		for(int j : g[i]){
			if(used[j])
				continue;
			used[j] = 1;
			q.push(j);
			par[0][j] = i;
			depth[j] = depth[i] + 1;
		}
	}
	//parent table fill
	for(int d = 1; d <= l; d++){
		for(int i = 0; i < n; i++){
			int mid = par[d-1][i];
			if(mid != -1)
				par[d][i] = par[d-1][mid];
		}
	}
}

int walk(int i, int k){ //i node, k distance up in logk
	for(int d = 0; d <= l && i!=-1; d++)
		if(((1<<d) & k) > 0)
			i = par[d][i];
	return i;
}

int lca(int i, int j){
	if(depth[i] > depth[j])
		i = walk(i, depth[i] - depth[j]);
	if(depth[j] > depth[i])
		j = walk(j, depth[j] - depth[i]);
	if(i == j)
		return i;
	for(int d = l; d >= 0; d--){
		if(par[d][i] != par[d][j]){
			i = par[d][i];
			j = par[d][j];
		}
	}
	return par[0][i];
}

int pathdis(int u, int v){
	int anc = lca(u, v);
	return depth[u] + depth[v] - (2 * depth[anc]); 
}

int main(){
	cin>>n;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	build(0);
}