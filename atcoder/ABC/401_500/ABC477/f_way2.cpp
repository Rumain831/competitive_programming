#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: grid, 長方形領域, セグ木

template<class Tr=P>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    return P(a.first+b.first, a.second+b.second);
  }
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(int n){
    N=pow2(n);
    iden=P(0, 0);
    tree.resize(2*N, iden);
    //for(int i=0; i<n; i++) tree[N+i]=a[i];
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, Tr x){  //0-indexed
    int i=node+N;
    tree[i]=x; 
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

struct Query{
  int id, i, j, sg;
  Query(int id, int i, int j, int sg):id(id), i(i), j(j), sg(sg){}
  bool operator<(const Query& other)const{
    if(j!=other.j) return j<other.j;
    else return id<other.id;
  } 
};

int main(void){
  int n, m, q; cin >> n >> m >> q;
  vector<int> l(n), r(n);
  vector<vector<P>> ch(m+2);
  for(int i=0; i<n; i++){
    cin >> l[i] >> r[i];
    ch[l[i]].emplace_back(i+1, 1);
    ch[r[i]+1].emplace_back(i+1, -1);
  }
  vector<ll> ans(q);
  vector<Query> qu;
  segtree seg;
  seg.build(n+1);
  for(int i=0; i<q; i++){
    int a, b, c, d; cin >> a >> b >> c >> d;
    qu.emplace_back(i, b, d, 1);
    qu.emplace_back(i, a-1, d, -1);
    qu.emplace_back(i, b, c-1, -1);
    qu.emplace_back(i, a-1, c-1, 1);
  }
  sort(begin(qu), end(qu));
  int qs=qu.size(), qi=0;
  for(int i=0; i<=m; i++){
    for(auto [id, sg]:ch[i]){
      if(sg==1) seg.update(id, P(1, 1-l[id-1]));
      else{
        seg.update(id, P(0, r[id-1]-l[id-1]+1));
      }
    }
    while(qi<qs){
      if(qu[qi].j!=i) break;
      int l=qu[qi].i, sg=qu[qi].sg, ni=qu[qi].id;
      auto [a, b]=seg.query(0, l);
      ans[ni]+=sg*(a*i+b);
      qi++;
    }
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}