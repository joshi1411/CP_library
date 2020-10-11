struct Fenwick {
    vector<int> bit;  // binary indexed tree
    int n;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    Fenwick(vector<int> a) : Fenwick(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
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


