#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using tu = tuple<ll, ll, int>;

//Tags: 全探索

void solve(){
  int n; cin >> n;
  vector<ll> a(n+1), b(n+1);
  vector<tu> vec;
  multiset<P> s;
  ll sum=0;
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
    sum+=a[i];
    vec.emplace_back(a[i]-b[i], a[i], i);
  }
  vec.emplace_back(0, 1e18, n);
  sort(begin(vec), end(vec), [](const tu& p, const tu& q){
    auto [ab1, a1, i1]=p;
    auto [ab2, a2, i2]=q;
    if(ab1!=ab2) return ab1>ab2;
    else if(a1!=a2) return a1<a2;
    else return i1<i2;
  });
  vector<ll> mi(n+2, 1e18);
  for(int i=n; i>=0; i--) mi[i]=min(mi[i+1], get<1>(vec[i]));
  ll ans=sum, ab=0;
  for(int x=0; x<n; x++){
    auto [abx, ax, ix]=vec[x];
    ab+=abx;
    s.emplace(ax, abx);
    if(x<n-1){//大きい方から順当にクーポンを使う
      ll now=sum-ab+mi[x+1]*max<ll>(2*(x+1)-n, 0);
      ans=min(ans, now);
    }
    {//SのうちAiが最小のもの連打
      auto [a0, ab0]=*begin(s);
      ll now=sum-ab;
      now+=ab0;
      now-=get<0>(vec[x+1]);
      now+=a0*max<ll>(2*(x+1)-n, 0);
      ans=min(ans, now);
    }
  }
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}