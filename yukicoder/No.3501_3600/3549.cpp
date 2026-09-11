#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 桁dp
//Level: 2.5

ll f(ll n){
  if(n==0) return 0ll;
  string s=to_string(n);
  int d=s.size();
  ll cnt[d+1][10][2]={};
  cnt[0][0][0]=1;
  for(int i=0; i<d; i++){
    int now=s[i]-'0';
    for(int j=0; j<10; j++)for(int ika=0; ika<2; ika++){
      int r=(ika?9:now);
      for(int x=0; x<=r; x++){
        int nj=max(j, x);
        int nika=(ika||x<now);
        cnt[i+1][nj][nika]+=cnt[i][j][ika];
      }
    }
  }
  ll ans=0;
  for(int i=0; i<10; i++) ans+=(cnt[d][i][0]+cnt[d][i][1])*i;
  return ans;
}

int main(void){
  int t; cin >> t;
  while(t--){
    ll l, r; cin >> l >> r;
    cout << f(r)-f(l-1) << '\n';
  }
  return 0; 
}