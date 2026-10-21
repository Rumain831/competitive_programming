#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<int, P>;

//Tags: 文字列, 全探索

int main(void){
  int n; cin >> n;
  vector<vector<P>> cnt(51);
  unordered_map<string, ll> all;
  vector<string> s(n);
  vector<P> hash(n);
  ll ans=0;
  ll Base1=91138233, Base2=3, mod=1e9+7;
  for(int i=0; i<n; i++){
    string t; cin >> t;
    s[i]=t;
    int m=t.size();
    vector<PP> sub;
    P ha;
    for(int l=0; l<m; l++){
      ll h1=1, h2=1;
      for(int r=l; r<m; r++){
        ll x=t[r]-'a';
        h1*=Base1, h2*=Base2;
        h1+=x, h2+=x;
        h1%=mod, h2%=mod;
        sub.emplace_back(r-l+1, P(h1, h2));
        if(l==0&&r==m-1) ha=P(h1, h2);
      }
    }
    sort(begin(sub), end(sub));
    sub.erase(unique(begin(sub), end(sub)), end(sub));
    for(auto&[l, q]:sub) cnt[l].push_back(q);
    all[t]++;
    hash[i]=ha;
  }
  for(int i=1; i<=50; i++) sort(begin(cnt[i]), end(cnt[i]));
  for(int i=0; i<n; i++){
    auto ha=hash[i];
    int m=s[i].size();
    ll x=upper_bound(begin(cnt[m]), end(cnt[m]), ha)-lower_bound(begin(cnt[m]), end(cnt[m]), ha);
    ans+=x-1;
  }
  for(auto&[_, x]:all) ans-=x*(x-1)/2;
  cout << ans << endl;
  return 0; 
}