#include<iostream>
#include<vector>
using namespace std;

//Tags: セグ木

struct info{
  int max=-1e9, min=1e9, min_id=1e9, max_id=1e9;
  info(){}
  info(int x, int i):max(x), min(x), min_id(i), max_id(i){}
};

template<class Tr=info>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    info ans;
    if(a.max>b.max) ans.max=a.max, ans.max_id=a.max_id;
    else ans.max=b.max, ans.max_id=b.max_id;
    if(a.min<b.min) ans.min=a.min, ans.min_id=a.min_id;
    else ans.min=b.min, ans.min_id=b.min_id;
    return ans;
  }
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(vector<int> &a){
    int n=a.size();
    N=pow2(n);
    iden=info();
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=info(a[i], i);
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, int x){  //0-indexed
    int i=node+N;
    tree[i]=info(x, node); i/=2;
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

int main(void){
  int n, m; cin >> n >> m;
  vector<int> p(n);
  for(auto&x:p) cin >> x;
  segtree seg;
  seg.build(p);
  while(m--){
    int l, r; cin >> l >> r; l--, r--;
    auto res=seg.query(l, r);
    swap(res.max_id, res.min_id);
    seg.update(res.min_id, res.min);
    seg.update(res.max_id, res.max);
  }
  for(int i=0; i<n; i++) cout << seg.query(i, i).min << ' ';
  return 0; 
}