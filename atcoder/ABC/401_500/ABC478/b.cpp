#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索

int main(void){
  int n, v; cin >> n >> v;
  int ans=0;
  vector<int> w(n);
  for(auto&x:w) cin >> x;
  for(int i=0; i<n-2; i++)for(int j=i+1; j<n-1; j++)for(int k=j+1; k<n; k++){
    int p=i+j+k+3;
    if(p<=v) ans=max(ans, w[i]+w[j]+w[k]);
  }
  cout << ans << endl;
  return 0; 
}