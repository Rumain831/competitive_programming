#include<iostream>
#include<vector>
using namespace std;

//Tags: bit全探索

int main(void){
  int n, w, k; cin >> n >> w >> k;
  vector<int> h(n);
  int ans=0;
  for(auto&x:h) cin >> x, ans+=x;
  int mx=(1<<n);
  for(int i=1; i<mx; i++){
    int c=__builtin_popcount(i);
    if(c>k) continue;
    vector<int> imos(n+1);
    for(int j=0; j<n; j++)if(i>>j&1){
      int l=max(0, j-(w-1)/2), r=min(n-1, j+w/2);
      imos[l]++, imos[r+1]--;
    }
    for(int j=0; j<n; j++) imos[j+1]+=imos[j];
    int now=0;
    for(int j=0; j<n; j++)if(imos[j]==0) now+=h[j];
    ans=min(ans, now);
  }
  cout << ans << endl;
  return 0; 
}