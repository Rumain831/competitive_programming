#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  int n, q, m; cin >> n >> q >> m;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  string s; cin >> s;
  auto f=[&](){
    int now=0;
    vector<int> get(n);
    ll ans=0;
    for(int i=0; i<q; i++){
      int nxt=now;
      if(s[i]=='L') nxt--;
      else if(s[i]=='R') nxt++;
      else if(s[i]=='B') nxt=0;
      else{
        if(!get[now]) get[now]++, ans+=a[now];
      }
      if(nxt<0) nxt=0;
      else if(nxt>=n) nxt=n-1;
      now=nxt;
    }
    return ans;
  };
  while(m--){
    int t; cin >> t;
    if(t==1){
      int p; char c; cin >> p >> c; p--;
      s[p]=c;
    } 
    else{
      cout << f() << '\n';
    }
  }
  return 0; 
}