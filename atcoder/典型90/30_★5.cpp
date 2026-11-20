#include<iostream>
#include<vector>
using namespace std;

//Tags: 整数, 素数
//解説URL: https://twitter.com/e869120/status/1389349360866009090

int main(void){
  int n, k; cin >> n >> k;  
  vector<int> yakusu(n+1, -1), cnt(n+1);
  for(int i=2; i<=n; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    while(copy<=n){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      cnt[copy]++;
      copy+=i;
    }
  }
  int ans=0;
  for(int i=2; i<n+1; i++) ans+=(cnt[i]>=k);
  cout << ans << endl; 
  return 0;
}