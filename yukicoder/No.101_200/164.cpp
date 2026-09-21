#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数, N進法
//Level: 2

int mx(string& s){
  int ans=-1;
  for(auto p:s){
    if(isdigit(p)) ans=max(ans, p-'0');
    else ans=max(ans, p-'A'+10);
  }
  return ans;
}

ll val(string& s){
  ll d=mx(s)+1, ans=0;
  for(auto p:s){
    ll x=(isdigit(p)?p-'0':p-'A'+10);
    ans=(ans*d+x);
  }
  return ans;
}

int main(void){
  int n; cin >> n;
  ll ans=9e18;
  while(n--){
    string s; cin >> s;
    ans=min(ans, val(s));
  }
  cout << ans << endl;
  return 0; 
}