#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  vector<int> know(n);
  know[0]=1;
  while(m--){
    int a, b; cin >> a >> b; 
    if(know[a]) know[b]++;
  }
  int ans=0;
  for(int i=0; i<n; i++) ans+=(know[i]>0);
  cout << ans << endl;
  return 0; 
}