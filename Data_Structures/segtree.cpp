/*Ashish Joshi
 NIT Hamirpur */

#include<bits/stdc++.h>
using namespace std;

struct segtree {

/* point update set(i, v) => a[i] = v .. in O(log2n)
query(l, r) => query from l to (r-1) of a[i]
 0 indexed , x : 2*x + 1 , 2*x + 2 */

	int siz;

	vector<long long> sums;

	void init(int n){
		siz = 1;
		while(siz < n)siz *= 2;
		sums.assign(4*siz, 0LL);
	}

	void build(vector<int> &a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				sums[x] = a[lx];
			}
			return ;
		}
		int mid = (lx + rx) / 2;
		build(a, x * 2 + 1, lx, mid);
		build(a, x * 2 + 2, mid, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void build(vector<int> &a){
		build(a, 0, 0, siz);
	}

	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			sums[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		if( i < mid ){
			set(i, v, 2 * x + 1, lx, mid);
		} else {
			set(i, v, 2 * x + 2, mid, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void set(int i, int v){
		set(i, v, 0, 0, siz);
	}

	long long sum(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return 0;
		if(lx >= l && rx <= r)return sums[x];
		int mid = (lx + rx) / 2;
		long long s1 = sum(l, r, 2 * x + 1, lx, mid);
		long long s2 = sum(l, r, 2 * x + 2, mid, rx);
		return s1 + s2;
	}

	long long sum(int l, int r){
		return sum(l, r, 0, 0, siz);
	}

};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	segtree st;
	st.init(n);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	st.build(a);

}


