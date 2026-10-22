#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 文字列, 数え上げ
//Level: 3

vector<vector<ll>> comb(int n, ll mod){
  vector nck(n+1, vector<ll>(n+1));
  for(int i=0; i<=n; i++)for(int j=0; j<=i; j++){
    if(j==0||j==i) nck[i][j]=1;
    else nck[i][j]=nck[i-1][j-1]+nck[i-1][j], nck[i][j]%=mod;
  }
  return nck;
}

int main(void){
  string s; cin >> s;
  int cnt[26]={};
  for(auto p:s) cnt[p-'A']++;
  ll ans=1, n=s.size(), mod=573;
  auto nCk=comb(n, mod);
  for(auto x:cnt){
    ans*=nCk[n][x], ans%=mod;
    n-=x;
  }
  cout << (ans-1+mod)%mod << endl;
  return 0; 
}