#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: 幾何, 円環
//解説URL: https://twitter.com/e869120/status/1383635232134287360

template<class Tr=ll>
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
    if(r<l) return 0;
    return sum(r)-sum(l-1);
  }
};


int main(void){
  int n, m; cin >> n >> m;
  vector<P> arc;
  for(int i=0; i<m; i++){
    int l, r; cin >> l >> r;
    arc.emplace_back(l, r);
  }
  sort(begin(arc), end(arc), [&](const P& a, const P& b){
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
  });
  ll ans=0;
  BIT bit(n);
  for(int i=0; i<m; i++){
    auto [l, r]=arc[i];
    ans+=bit.range(l+1, r-1);
    bit.add(r, 1);
  }
  cout << ans << endl;
  return 0; 
}