#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: 座標圧縮, 二分探索, クエリ先読み

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
    return sum(r)-sum(l-1);
  }
};


int main(void){
  int n, x, y; cin >> n >> x >> y;
  vector<P> p;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    p.emplace_back(a, b);
  }
  sort(begin(p), end(p));
  ll ans=0;
  vector<P> qu;
  for(int i=0; i<n; i++){
    auto [a, b]=p[i];
    int k=lower_bound(begin(p), end(p), P(x-a, -1))-begin(p);
    k=max(k, i+1);
    if(k>=n) continue;
    qu.emplace_back(k, y-b);
  }
  sort(rbegin(qu), rend(qu));
  int id=0, m, qm=qu.size();
  map<int, int> dict;
  vector<int> sb;
  {
    map<int, int> mp;
    for(auto [a, b]:p) mp[b]++;
    mp[2e9+1]++;
    int c=0;
    for(auto [b, _]:mp) dict[b]=++c, sb.push_back(b);
    m=dict.size();
  }
  BIT bit(m);
  for(int i=n-1; i>=0; i--){
    auto [a, b]=p[i];
    int bi=dict[b];
    bit.add(bi, 1);
    while(id<qm){
      auto [ki, tar]=qu[id];
      if(ki!=i) break;
      int l=lower_bound(begin(sb), end(sb), tar)-begin(sb); l++;
      ans+=bit.range(l, m);
      id++;
    }
  }
  cout << ans << endl;
  return 0; 
}