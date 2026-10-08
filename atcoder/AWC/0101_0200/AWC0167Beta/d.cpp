#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: functional graph, ダブリング

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector db(61, vector<int>(n));
  for(int i=0; i<n; i++){
    if(i==n-1) db[0][i]=i;
    else{
      ll x=abs(a[i]+a[i+1]);
      int y;
      if(x%2) y=max(i-1, 0);
      else y=i+1; 
      db[0][i]=y;
    }
  }
  for(int K=1; K<61; K++)for(int i=0; i<n; i++){
    db[K][i]=db[K-1][db[K-1][i]];
  }
  int now=0, c=0;
  while(k){
    if(k&1) now=db[c][now];
    c++, k/=2;
  }
  cout << now+1 << endl;
  return 0; 
}