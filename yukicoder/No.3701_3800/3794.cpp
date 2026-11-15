#include<iostream>
#include<map>
using namespace std;
using ll = long long;

//Tags: map
//Level: 1.5

int main(void){
  int n, m; cin >> n >> m;
  map<string, ll> cnt;
  while(n--){
    string s; ll p; cin >> s >> p;
    cnt[s]=p;
  }
  ll ans=0;
  while(m--){
    string s; cin >> s;
    ans+=cnt[s];
  }
  cout << ans << endl;
  return 0; 
}