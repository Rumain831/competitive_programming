#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 二分探索

int main(void){
  int n; cin >> n;
  vector<int> s(n), c(n), t(n);
  for(int i=0; i<n; i++){
    cin >> s[i] >> c[i];
    t[i]=s[i];
  }
  sort(begin(t), end(t));
  ll ans=0;
  for(int i=0; i<n; i++){
    if(s[i]>=c[i]) continue;
    ll k=lower_bound(begin(t), end(t), c[i])-lower_bound(begin(t), end(t), s[i]);
    ans+=k-1;
  }
  cout << ans << endl;
  return 0; 
}