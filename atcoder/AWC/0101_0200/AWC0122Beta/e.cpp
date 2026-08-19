#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using tu = tuple<int, int, int>;

//Tags: 種類数

template<class Tr=int>
struct BIT{
  int n;
  vector<Tr> bit;
  BIT(int size): n(size), bit(size+1, 0) {};

  void add(int i, Tr x){ //1-indexed
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }

  Tr sum(int i){ //1-indexed
    Tr ans=0;
    while(i>0){
      ans+=bit[i];
      i-=i&-i;
    }
    return ans;
  }

  Tr range(int l, int r){ //1-indexed
    return sum(r)-sum(l-1);
  }
};

int main(void){
  int n, k, q; cin >> n >> k >> q;
  vector<int> L(n), R(n), x(n);
  for(int i=0; i<n; i++) cin >> L[i] >> R[i] >> x[i];
  vector<int> sign(k+1);
  for(int i=1; i<=k; i++) sign[i]=i;
  for(int i=0; i<n; i++){
    for(int j=1; j<=k; j++){
      if(L[i]<=sign[j]&&sign[j]<=R[i]) sign[j]=x[i];
    }
  }
  vector<tu> query;
  for(int i=0; i<q; i++){
    int a, b; cin >> a >> b;
    query.emplace_back(b, a, i);
  }
  sort(begin(query), end(query));
  int id=0;
  BIT bit(k+1);
  vector<int> last(k+1, 0), ans(q);
  for(int i=1; i<=k; i++){
    int now=sign[i];
    bit.add(last[now]+1, -1);
    last[now]=i;
    bit.add(last[now]+1, 1);
    while(id<q){
      auto [b, a, qi]=query[id];
      if(i!=b) break;
      ans[qi]=bit.range(a+1, b+1);
      id++;
    }
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}