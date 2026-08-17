#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int mi=2e9;
  while(m--){
    int b; cin >> b;
    mi=min(mi, b);
  }
  int ans=0;
  for(int i=0; i<n; i++){
    if(a[i]<=mi){
      ans++, mi-=a[i];
    }
  }
  cout << ans << endl;
  return 0; 
}