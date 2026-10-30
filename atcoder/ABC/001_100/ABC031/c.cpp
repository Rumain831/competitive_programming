#include<iostream>
#include<vector>
using namespace std;

//Tags: ゲーム, 全探索

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int maxao=-1e9, ans=-1e9;
  for(int i=0; i<n; i++){
    int nowma=-1e9, ansnow=-1e9;
    for(int j=0; j<n; j++){
      if(i==j) continue;
      int left=min(i, j), right=max(i, j);
      int l=right-left+1;
      int ta=0, ao=0;
      for(int k=0; k<l; k++){
        if(k%2) ao+=a[left+k];
        else ta+=a[left+k];
      }
      if(nowma<ao) nowma=ao, ansnow=ta;
    }
    ans=max(ansnow, ans);
  }
  cout << ans << endl;
  return 0;
}