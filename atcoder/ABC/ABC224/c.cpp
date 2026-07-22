#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 全探索, 幾何

int main(void){
  int n; cin >> n;
  vector<ll> x(n), y(n);
  int ans=0;
  for(int i=0; i<n; i++) cin >> x[i] >> y[i];
  for(int i=0; i<n-2; i++)for(int j=i+1; j<n-1; j++)for(int k=j+1; k<n; k++){
    P p={x[j]-x[i], y[j]-y[i]};
    P q={x[k]-x[i], y[k]-y[i]};
    if(p.first*q.second!=p.second*q.first) ans++;
  }
  cout << ans << endl;
  return 0; 
}