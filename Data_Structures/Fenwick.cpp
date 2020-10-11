
template <typename T>
struct Fenwick{
   int n;
   vector<T> fenw;
   Fenwick(int n){
      this->n = n;
      fenw.assign(n,0);
   }
   Fenwick(vector<T> a) : Fenwick((int)a.size()){
      for(int i = 0; i < a.size(); ++i){
         update(i,a[i]);
      }
   }
   T sum(int r){
      long long res = 0;
      while(r>=0){
         res += fenw[r];
         r = r&(r+1);
         r--;
      }
      return res;
   }
   T sum(int l,int r){
      return sum(r)-sum(l-1);
   }
   void update(int ind,T val){
      while(ind < n){
         fenw[ind] += val;
         ind = ind | (ind+1);
      }
   }
   void range_upd(int l, int r, T val){
      update(l,val);
      update(r+1,-val);
   }
};


//1 based indexing
struct Fenwick1 {
    vector<int> bit;  // binary indexed tree
    int n;

    Fenwick1(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    Fenwick1(vector<int> a)
        : Fenwick1(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};


