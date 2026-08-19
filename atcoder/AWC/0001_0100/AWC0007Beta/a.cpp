#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  int n, m; cin >> n >> m;
  ll mi=1e9, sum=0;
  for(int i=0; i<n; i++){
    ll e; cin >> e;
    mi=min(mi, e);
  }
  for(int i=0; i<m; i++){
    ll c; cin >> c; sum+=c;
  }
  cout << sum*mi << endl;
  return 0;
}