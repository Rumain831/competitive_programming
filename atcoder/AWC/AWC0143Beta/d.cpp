#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Tags: 座標圧縮, 二分探索, BIT

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
  int n, q; cin >> n >> q;
  vector<int> s(n), val={-1};
  for(auto&x:s) cin >> x, val.push_back(x);
  vector<int> t(q), v(q);
  for(int i=0; i<q; i++){
    cin >> t[i] >> v[i]; t[i]--;
    val.push_back(v[i]);
  }
  auto [vec, dict]=cc(val);
  int m=dict.size();
  BIT bit(m);
  auto med=[&](){
    int left=1, right=m;
    while(right-left>1){
      int mid=(left+right)/2;
      int now=bit.range(1, mid);
      if(now>=(n+1)/2) right=mid;
      else left=mid;
    }
    return right;
  };
  for(int i=0; i<n; i++) bit.add(dict[s[i]], 1);
  for(int i=0; i<q; i++){
    bit.add(dict[s[t[i]]], -1);
    s[t[i]]=v[i];
    bit.add(dict[s[t[i]]], 1);
    int x=med();
    cout << bit.range(1, x-1) << '\n';
  }
  return 0; 
}