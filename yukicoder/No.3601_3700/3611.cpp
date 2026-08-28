#include<iostream>
#include<vector>
using namespace std;

//Tags: 実装, ランレングス圧縮
//Level: 1.5

void solve(){
  int n; cin >> n;
  vector<int> h(n);
  for(auto&x:h) cin >> x;
  string s, t;
  for(int i=0; i<n-1; i++) s+=(h[i]>h[i+1]?'>':'<');
  int id=0;
  while(id<n-1){
    char now=s[id];
    while(id<n-1&&s[id]==now) id++;
    t+=now;
  }
  cout << (t=="><><"?"Yes":"No") << '\n';
}

int main(void){
  int n; cin >> n;
  while(n--){
    solve();
  }
  return 0; 
}