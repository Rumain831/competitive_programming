#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 愚直

int main(void){
  int n; cin >> n;
  vector<vector<ll>> sc(n);
  for(int i=0; i<n; i++){
    ll c, l; cin >> c >> l; c--;
    sc[c].push_back(l);
  }
  ll ans=0;
  for(int i=0; i<n; i++){
    int m=sc[i].size();
    for(int p=0; p<m-1; p++)for(int q=p+1; q<m; q++){
      ans+=abs(sc[i][p]-sc[i][q]);
    }
  }
  cout << ans << endl;
  return 0; 
}