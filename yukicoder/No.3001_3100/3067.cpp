#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation
//Level: 1.5

int main(void){
  int n, T; cin >> n >> T;
  vector<int> t(n-1);
  for(auto&x:t) cin >> x;
  vector<int> add(n);
  int k; cin >> k;
  for(int i=0; i<k; i++){
    int x; cin >> x, x--;
    add[x]++;
  }
  int ans=0, get=0;
  for(int i=0; i<n-1; i++){
    if(T<=t[i]){
      int need=(t[i]-T)/10+1;
      if(get<need){
        cout << -1 << endl; return 0;
      }
      ans+=need, get-=need, T+=need*10;
    }
    T-=t[i];
    if(add[i+1]) get++;
  }
  cout << ans << endl;
  return 0; 
}