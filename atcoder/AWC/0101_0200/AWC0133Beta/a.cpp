#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<ll> t(n), cancel(n);
  for(int i=0; i<n; i++) cin >> t[i]; 
  for(int i=0; i<m; i++){
    int d; cin >> d; d--;
    cancel[d]++;
  } 
  ll ans=0;
  for(int i=0; i<n; i++){
    if(cancel[i]) continue;
    ans+=t[i]/k;
  }
  cout << ans << endl;
  return 0; 
}