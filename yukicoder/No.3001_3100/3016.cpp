#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 差分更新
//Level: 2

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n-1);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  set<int> ans;
  ll mi=0, now=0;
  for(int i=0; i<n-1; i++) now+=abs(a[i]-b[i]);
  ans.insert(a[n-1]);
  mi=now;
  for(int i=n-2; i>=0; i--){
    now-=abs(a[i]-b[i]);
    now+=abs(a[i+1]-b[i]);
    if(mi==now) ans.insert(a[i]);
    else if(mi>now){
      mi=now;
      ans.clear();
      ans.insert(a[i]);
    }
  }
  cout << ans.size() << endl;
  for(auto p:ans) cout << p << ' '; cout << endl;
  return 0; 
}