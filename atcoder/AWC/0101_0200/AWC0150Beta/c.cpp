#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  int ans=0;
  vector<int> used(m);
  while(n--){
    int p; cin >> p; p--;
    while(used[p]) p++;
    if(p<m&&!used[p]) ans++, used[p]=1;
  }  
  cout << ans << endl;
  return 0; 
}