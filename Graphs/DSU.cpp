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

vector<int> parent,rank; //resize before using
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
