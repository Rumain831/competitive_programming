#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

bool judge(ll x){
  string s=to_string(x);
  int d=s.size();
  for(int i=0; i<d-1; i++){
    if(s[i]==s[i+1]&&s[i]=='0') return true;
  }
  return false;
}

void solve(){
  ll k; cin >> k;
  //少なくともk*100は条件を満たすので、k, 2k, ..., 100kまで試せばOK
  for(ll i=1; i<=100; i++){
    if(judge(k*i)){
      cout << k*i << '\n'; return;
    }
  }
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}
