#include<iostream>
#include<vector>
#include<tuple>
#include<map>
#include<algorithm>
using namespace std;
using P = pair<int, int>;
using tu = tuple<int, int, int>;

//Tags: LIS

template<class Tr=P>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    return P(max(a.first, b.first), a.second+b.second);
  }
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(int n){
    N=pow2(n);
    iden=P(-1, 0);
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=P(-1, 0);
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, int type, int x){  //0-indexed
    int i=node+N;
    if(type==0) tree[i].first=x;
    else tree[i].second+=x;
    i/=2;
    while(i>0){
      tree[i]=op(tree[2*i], tree[2*i+1]); i/=2;
    }
    return;
  }

  Tr query(int s, int t){  //0-indexed
    int left=s+N, right=t+N;
    Tr ansl=iden, ansr=iden;
    while(left<=right){
      if(left%2==1){
        ansl=op(ansl, tree[left]); left++;
      }
      if(right%2==0){
        ansr=op(tree[right], ansr); right--;
      }
      left/=2, right/=2;
    }
    return op(ansl, ansr);
  }
};

pair<vector<int>, map<int, int>> cc(vector<int>& a){ //座標圧縮
  vector<int> p=a;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  map<int, int> f;
  int l=p.size();
  for(int i=0; i<l; i++) f[p[i]]=i;
  vector<int> ans;
  for(auto& x:a) ans.push_back(f[x]);
  return {ans, f};
}

int main(void){
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  auto [aa, dict]=cc(a);
  vector<tu> query;
  for(int i=0; i<q; i++){
    int l, r; cin >> l >> r; l--, r--;
    query.emplace_back(r, l, i);
  }
  sort(begin(query), end(query));
  segtree seg;
  seg.build(n+1);
  vector<int> ans(q);
  int id=0;
  for(int i=0; i<n; i++){
    int hardle=seg.query(aa[i], n).first;
    if(hardle!=-1) seg.update(hardle, 1, 1);
    seg.update(aa[i], 0, i);
    while(id<q){
      auto [r, l, qi]=query[id];
      if(i!=r) break;
      int x=seg.query(l, r).second;
      ans[qi]=r-l+1-x;
      id++;
    }
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}