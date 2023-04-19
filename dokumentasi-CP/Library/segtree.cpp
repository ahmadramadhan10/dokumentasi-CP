struct node{
  // node tiap tree tergantung kebutuhan
};

template<int MAXN, typename T>
struct Segtree {
  vector<T>t;
  Segtree() {
    t.assign(MAXN * 4, 2e9);
  }

  T comb(T x, T y) {
    // berlaku pada operasi komutatif
    // combinasi tergantung kebutuhan
  }

  void build(int v, int l, int r) {
    if(l == r) {
      t[v] = A[l];
    } else {
      int mid = (l + r) >> 1;
      build(v << 1, l, mid);
      build(v << 1 | 1, mid + 1 ,r);
      t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
  }

  void update(int v, int l, int r, int pos, T val) {
    if(l == r && l == pos) {
      t[v] = val;
    } else {
      int mid = (l + r) >> 1;
      if(pos <= mid)
        update(v << 1, l, mid, pos, val);
      else
        update(v << 1 | 1, mid + 1, r, pos, val);
      t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
  }

  T get(int v, int l, int r, int lq, int rq) {
    if(r < lq || l > rq || l > r) {
      return inf;
    }
    if(lq <= l && r <= rq) {
      return t[v];
    }
    int mid = (l + r) >> 1;
    T left = get(v << 1, l, mid, lq, rq);
    T right = get(v << 1 | 1, mid + 1, r, lq, rq);
    return comb(left,right);
  }
};