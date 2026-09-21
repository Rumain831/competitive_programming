#include<iostream>
using namespace std;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  int mx=0, ans;
  for(int i=0; i<n; i++){
    int sum=0, low=1e9, high=0;
    for(int j=0; j<m; j++){
      int x; cin >> x; sum+=x;
      low=min(low, x);
      high=max(high, x);
    }
    sum-=low+high;
    if(mx<sum){
      mx=sum, ans=i+1;
    }
  }
  cout << ans << endl;
  return 0; 
}