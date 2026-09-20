#include<iostream>
#include<vector>
using namespace std;

//Tags: grundy数, ゲーム
//Level: 3

int main(void){
  int n; cin >> n;
  vector<int> g(n+1);
  for(int i=2; i<=n; i++){
    int cnt[3]={};
    int gx=g[i/2]^g[i-i/2];
    if(gx<=2) cnt[gx]++;
    if(i>=3){
      int r=i%3;
      gx=(r==1?g[i/3+1]:g[i/3]);
      if(gx<=2) cnt[gx]++;
    }
    for(int j=0; j<3; j++)if(cnt[j]==0){
      g[i]=j; break;
    }
  }
  cout << (g[n]?"A":"B") << endl;
  return 0; 
}