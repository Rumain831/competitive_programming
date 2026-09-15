#include<iostream>
#include<vector>
using namespace std;

//Tags: グラフ

int main(void){
  int n; cin >> n;
  int ans=0;
  vector<int> deg(n);
  for(int i=0; i<n; i++){
    int t; cin >> t; t--;
    deg[t]++;
  }
  for(int i=0; i<n; i++)if(deg[i]==0) ans++;
  cout << ans << endl;
  return 0; 
}