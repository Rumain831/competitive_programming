#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, k; cin >> n >> k;
  vector<double> r(n);
  for(int i=0; i<n; i++) cin >> r[i];
  sort(r.rbegin(), r.rend());
  double ans=0;
  for(int i=k-1; i>=0; i--){
    ans=(ans+r[i])/2.0;
  }
  printf("%.10f\n", ans);
  return 0;
}