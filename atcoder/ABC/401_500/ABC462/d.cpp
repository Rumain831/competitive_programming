#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//イベントソートによる解法　imos法を用いた方がより簡便
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
    if(l>r) return 0ll;
    return sum(r)-sum(l-1);
  }
};


int main(void){
  int n, d; cin >> n >> d;
  vector<int> s(n), t(n);
  int mx=1e6;
  vector<P> event;
  for(int i=0; i<n; i++){
    cin >> s[i] >> t[i]; 
    event.emplace_back(s[i], i);
  }
  BIT ok(mx+1);
  sort(event.begin(), event.end());
  ll ans=0, id=0, nume=event.size();
  for(int i=1; i<=mx-d+1; i++){
    while(id<nume){
      auto [time, ni]=event[id];
      if(time!=i) break;
      ok.add(t[ni], 1);
      id++;
    }
    int end=i+d-1;
    ll num=ok.range(end+1, mx);
    ans+=num*(num-1)/2;
  }
  cout << ans << endl;
  return 0; 
}