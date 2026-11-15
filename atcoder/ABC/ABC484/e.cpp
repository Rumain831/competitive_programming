#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: 座標圧縮, 累積和

pair<vector<ll>, map<ll, int>> cc(vector<ll>& a){ //座標圧縮
  vector<ll> p=a;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  map<ll, int> f;
  int l=p.size();
  for(int i=0; i<l; i++) f[p[i]]=i+1;
  vector<ll> ans;
  for(auto& x:a) ans.push_back(f[x]);
  return {ans, f};
}

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
  ll n, l, r; cin >> n >> l >> r;
  vector<ll> a(n), sum={0};
  for(auto&x:a) cin >> x, sum.push_back(sum.back()+x);
  auto [t, dict]=cc(sum);
  vector<P> sm(n+1);
  for(int i=0; i<=n; i++) sm[i]=P(sum[i], dict[sum[i]]);
  sort(begin(sm), end(sm));
  auto f=[&](ll tar){
    ll ans=0, now=0;
    BIT bit(n+2);
    bit.add(dict[0], 1);
    for(int i=0; i<n; i++){
      now+=a[i];
      auto it=upper_bound(begin(sm), end(sm), P(now-tar, 1e9));
      if(it==end(sm)){
        bit.add(dict[now], 1);
        continue;
      }
      auto [val, id]=*it;
      ll add=bit.range(id, n+1);
      ans+=add;
      bit.add(dict[now], 1);
    }
    return ans;
  };
  ll ans=f(r+1)-f(l);
  cout << ans << endl;
  return 0; 
}