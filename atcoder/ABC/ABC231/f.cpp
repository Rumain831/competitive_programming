#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: 平面走査

pair<vector<int>, map<int, int>> cc(vector<int>& a){ //座標圧縮
  vector<int> p=a;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  map<int, int> f;
  int l=p.size();
  for(int i=0; i<l; i++) f[p[i]]=i+1;
  vector<int> ans;
  for(auto& x:a) ans.push_back(f[x]);
  return {ans, f};
}

struct BIT{
  int n;
  vector<int> bit;
  BIT(int size): n(size), bit(size+1, 0) {};

  void add(int i, int x){ //1-indexed
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }

  int sum(int i){ //1-indexed
    int ans=0;
    while(i>0){
      ans+=bit[i];
      i-=i&-i;
    }
    return ans;
  }

  int range(int l, int r){ //1-indexed
    if(l>r) return 0;
    return sum(r)-sum(l-1);
  }
};


int main(void){
  int n; cin >> n;
  vector<P> gift(n);
  vector<int> b(n);
  for(auto&[p, _]:gift) cin >> p;
  for(auto&[_, p]:gift) cin >> p;
  sort(gift.begin(), gift.end());
  for(int i=0; i<n; i++) b[i]=gift[i].second;
  ll ans=0;
  auto [c, dict]=cc(b);
  int idx=0, m=dict.size();
  BIT bit(n);
  while(idx<n){
    vector<int> add;
    int na=gift[idx].first;
    while(idx<n&&gift[idx].first==na){
      add.push_back(c[idx]); 
      bit.add(c[idx], 1);
      idx++;
    }
    for(auto p:add){
      ans+=bit.range(p, m);
    }
  }
  cout << ans << endl;
  return 0;
}