#include<iostream>
#include<vector>
using namespace std;

//Tags: ゲーム, grundy数, dp
//解説URL: https://twitter.com/e869120/status/1389711962213261316

int main(void){
  int n; cin >> n;
  vector<int> w(n), b(n);
  for(auto&x:w) cin >> x;
  for(auto&x:b) cin >> x;
  int mw=50, mb=51*25;
  vector g(mw+1, vector<int>(mb+1));
  for(int i=0; i<=mw; i++)for(int j=0; j<=mb; j++){
    vector<int> used(mb+10);
    if(i>=1&&i+j<=mb) used[g[i-1][j+i]]++;
    if(j>=2){
      for(int k=1; k<=j/2; k++) used[g[i][j-k]]++;
    }
    for(int k=0; k<mb+10; k++)if(!used[k]){
      g[i][j]=k; break;
    }
  }
  int x=0;
  for(int i=0; i<n; i++) x^=g[w[i]][b[i]];
  cout << (x?"First":"Second") << endl;
  return 0; 
}