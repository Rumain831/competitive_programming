#include<iostream>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<int, ll>;

//Tags: 文字列, Simulation

int main(void){
  int q; cin >> q;
  queue<P> s;
  while(q--){
    int t; cin >> t;
    if(t==1){
      char c; ll d; cin >> c >> d;
      int x=c-'a';
      s.emplace(x, d);
    }
    else{
      ll cnt[26]={};
      ll d; cin >> d;
      while(d&&s.size()){
        auto [ci, x]=s.front();
        if(x<=d){
          s.pop();
          cnt[ci]+=x;
          d-=x;
        }
        else{
          cnt[ci]+=d;
          s.front().second-=d;
          d=0; break;
        }
      }
      ll ans=0;
      for(int i=0; i<26; i++) ans+=cnt[i]*cnt[i];
      cout << ans << '\n';
    }
  }
  return 0; 
}