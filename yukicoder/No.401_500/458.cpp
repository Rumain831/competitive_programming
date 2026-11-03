#include<iostream>
#include<vector>
using namespace std;
void chmax(int& a, int b){a=max(a, b);}

//Tags: dp, 整数, 素数
//Level: 2.5

int main(void){
  int n; cin >> n;
  int nn=20001;
  vector<int> yakusu(nn+1, -1), prime;
  for(int i=2; i<=nn; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    prime.push_back(i);
    while(copy<=nn){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  vector<int> dp(n+1, -1e9);
  dp[0]=0;
  for(auto p:prime)if(p<=n){
    vector<int> old(n+1, -1e9);
    swap(old, dp);
    for(int i=0; i<=n; i++)if(old[i]>=0){
      chmax(dp[i], old[i]);
      if(i+p<=n) chmax(dp[i+p], old[i]+1);
    }
  }
  cout << (dp[n]>=1?dp[n]:-1) << endl;
  return 0; 
}