/*Ashish Joshi
 NIT Hamirpur */

#include<bits/stdc++.h>
using namespace std;

// point update set(i, v) => a[i] = v .. in O(log2n)
// query(l, r) => query from l to (r-1) of a[i]
// 0 index x : 2*x + 1 , 2*x + 2

struct item{
	int m, c;
};

struct segtree {
	int siz;

	vector<item> values;

	item NEUTRAL_ELEM = {INT_MAX, 0};

	item merge(item a,item b){
		if(a.m < b.m) return a;
		if(a.m > b.m) return b;
		return {a.m, a.c + b.c};
	}

	void init(int n){
		siz = 1;
		while(siz < n)siz *= 2;
		values.resize(2*siz);
	}

	void build(vector<int> &a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				values[x] = {a[lx], 1};
			}
			return ;
		}
		int mid = (lx + rx) / 2;
		build(a, x * 2 + 1, lx, mid);
		build(a, x * 2 + 2, mid, rx);
		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}
	void build(vector<int> &a){
		build(a, 0, 0, siz);
	}

	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			values[x] = {v,1};
			return;
		}
		int mid = (lx + rx) / 2;
		if( i < mid ){
			set(i, v, 2 * x + 1, lx, mid);
		} else {
			set(i, v, 2 * x + 2, mid, rx);
		}
		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}

	void set(int i, int v){
		set(i, v, 0, 0, siz);
	}

	item calc(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return NEUTRAL_ELEM;;
		if(lx >= l && rx <= r)return values[x];
		int mid = (lx + rx) / 2;
		item s1 = calc(l, r, 2 * x + 1, lx, mid);
		item s2 = calc(l, r, 2 * x + 2, mid, rx);
		return merge(s1, s2);
	}

	item calc(int l, int r){
		return calc(l, r, 0, 0, siz);
	}

};


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	segtree st;
	st.init(n);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	st.build(a);
}


