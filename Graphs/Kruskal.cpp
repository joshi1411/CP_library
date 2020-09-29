/* Ashish Joshi
   NIT Hamirpur */

#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int u,v,weight;
	bool operator < (Edge const& other){
		return weight < other.weight;
	}
};

vector<int> parent,rank;
void make_set(int v){
	par[v]=1;
	rank[v]=1;
}

int find_set(int v){
	if(v==parent[v])return v;
	return parent[v]=find_set(parent[v]);
}

void union_set(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(rank[a]<rank[b])swap(a,b);
		par[b]=a;
		if(rank[a]==rank[b])rank[a]++;
	}
}



int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	parent.resize(n),rank.resize(n);
	vector<Edge> eg,mst;
	int ans=0;
	for(int i=0;i<n;i++)
		make_set(i);
	sort(eg.begin(),eg.end());

	for(Edge e : eg){
		if(find_set(e.u)!=find_set(e.v)){
			ans += e.weight;
			mst.push_back(e);
			union_set(e.u,e.v);
		}
	}
	
}