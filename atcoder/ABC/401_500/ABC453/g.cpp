#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 永続セグ木

template<class Tr=ll>
struct PerSegtree{
  struct Node{
    int l, r;
    Tr val;
    Node(int l, int r, Tr val):l(l), r(r), val(val){}
  };
  int N;
  Tr iden;
  vector<Node> tree;
  vector<int> root_id;

  Tr op(Tr a, Tr b){
    return a+b;
  }

  int build(int l, int r, const vector<Tr>& a){ //[l, r)
    int id=tree.size();
    tree.emplace_back(-1, -1, iden);
    if(r-l==1){
      tree[id].val=a[l];
      return id;
    }
    int mid=(l+r)/2;
    int left=build(l, mid, a);
    int right=build(mid, r, a);
    tree[id].l=left, tree[id].r=right;
    tree[id].val=op(tree[left].val, tree[right].val);
    return id;
  }

  //[l, r)を担当するNode ti、a_pos=xにする
  int upd(int ti, int l, int r, int pos, Tr x){
    int nti=tree.size();
    tree.push_back(tree[ti]);
    if(r-l==1){
      tree[nti].val=x;
      return nti;
    }
    int mid=(l+r)/2;
    int left=tree[nti].l, right=tree[nti].r;
    if(pos<mid) left=upd(left, l, mid, pos, x);
    else right=upd(right, mid, r, pos, x);
    tree[nti].l=left, tree[nti].r=right;
    tree[nti].val=op(tree[left].val, tree[right].val);
    return nti;
  }

  //[l, r)を担当するNode ti, クエリが[ql, qr)
  Tr qu(int ti, int l, int r, int ql, int qr){
    if(r<=ql||qr<=l) return iden;
    if(ql<=l&&r<=qr) return tree[ti].val;
    int mid=(l+r)/2;
    Tr L=qu(tree[ti].l, l, mid, ql, qr);
    Tr R=qu(tree[ti].r, mid, r, ql, qr);
    return op(L, R);
  }

  PerSegtree(const vector<Tr>& a){
    N=a.size();
    iden=0;
    int ri=build(0, N, a);
    root_id.push_back(ri);
  }

  void update(int ver, int i, Tr x){ //0-indexed
    int nti=upd(root_id[ver], 0, N, i, x);
    root_id.push_back(nti);
  }
  
  Tr query(int ver, int l, int r){ //[l, r), 0-indexed
    return qu(root_id[ver], 0, N, l, r);
  }

};

int main(void){
  int n, m, q; cin >> n >> m >> q;
  vector<ll> a(m);
  PerSegtree seg(a);
  vector<int> rt(n);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int x, y; cin >> x >> y; x--, y--;
      rt[x]=rt[y];
    }
    else if(t==2){
      int x, y; ll z; cin >> x >> y >> z; x--, y--;
      seg.update(rt[x], y, z);
      rt[x]=seg.root_id.size()-1;
    }
    else{
      int x, l, r; cin >> x >> l >> r; x--, l--;
      cout << seg.query(rt[x], l, r) << '\n';
    }
  }
  return 0; 
}