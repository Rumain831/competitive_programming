#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: 差分更新

template<class Tr=P>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    auto [a1, i1]=a;
    auto [b1, i2]=b;
    if(a1==b1) return min(a, b);
    else return (a1>b1?a:b);
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
    iden=P(-1, 1e9);
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=P(a[i], i);
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, int x){  //0-indexed
    int i=node+N;
    tree[i].first+=x; i/=2;
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
  vector<int> a(m), b(m);
  vector<vector<int>> first(n);
  vector<int> cnt(n);
  for(int i=0; i<m; i++){
    cin >> a[i] >> b[i]; a[i]--, b[i]--;
    first[a[i]].push_back(i);
    cnt[a[i]]++;
  }
  segtree seg;
  seg.build(cnt);
  for(int i=0; i<n; i++){
    for(auto p:first[i]){
      seg.update(i, -1);
      seg.update(b[p], 1);
    }
    auto [_, ans]=seg.query(0, n-1);
    cout << ans+1 << '\n';
    for(auto p:first[i]){
      seg.update(i, 1);
      seg.update(b[p], -1);
    }
  }
  return 0; 
}